#include "includes.h"

GPIO_InitTypeDef GPIO_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
RTC_InitTypeDef RTC_InitStructure;
RTC_DateTypeDef RTC_DateStructure;
RTC_TimeTypeDef RTC_TimeStructure;
// 函数声明
void tim3_init(void);
static void scr_temp_create();
static void scr_main_create();
static void scr_time_create();
static void change_theme();

// 颜色定义
#define BLACK 0x000000 // 黑色
#define GRAY 0x808080  // 灰色
#define WHITE 0xFFFFFF // 白色
#define BLUE 0x0000FF  // 蓝色

// 全局UI对象
// 主窗口
static lv_obj_t *scr_main = NULL;

// 温度窗口
static lv_obj_t *scr_temp = NULL;
static lv_obj_t *label_image_Temperature = NULL; // 温度图标
static lv_obj_t *label_image_Humidity = NULL;	 // 湿度图标
static lv_obj_t *tmp_bar = NULL;				 // 温度进度条
static lv_obj_t *hum_bar = NULL;				 // 湿度进度条
static lv_obj_t *label_dht11_Tdata = NULL;		 // 温度数据
static lv_obj_t *label_dht11_Hdata = NULL;		 // 湿度数据
static lv_obj_t *btn_get_tmp_hum = NULL;		 // 获取数据按钮
static float humidity;							 // 湿度
static float temperature;						 // 温度

// 时间窗口
static lv_obj_t *scr_time = NULL;
static lv_obj_t *arc = NULL; // 圆弧
static lv_obj_t *label_time; // 用于显示时间的标签
static char time_str[32];	 // 时间字符串

// 状态栏
static lv_obj_t *status_bar = NULL;
static lv_obj_t *time_label = NULL; // 时间标签

// 背景颜色
static u32 back_color = WHITE;

// 声明一个自定义的 TTF 字体
LV_FONT_DECLARE(my_font);

// 手势事件回调函数
static void gesture_event_cb(lv_event_t *e)
{
	lv_indev_t *indev = lv_indev_get_act();
	lv_dir_t dir = lv_indev_get_gesture_dir(indev);
	lv_obj_t *now = lv_scr_act();

	// 统一处理，形成闭环
	if (dir == LV_DIR_LEFT)
	{
		if (now == scr_main)
			lv_scr_load_anim(scr_temp, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, false);
		else if (now == scr_temp)
			lv_scr_load_anim(scr_time, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, false);
		else if (now == scr_time)
			lv_scr_load_anim(scr_main, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, false);
	}
	else if (dir == LV_DIR_RIGHT)
	{
		if (now == scr_main)
			lv_scr_load_anim(scr_time, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, false);
		else if (now == scr_temp)
			lv_scr_load_anim(scr_main, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, false);
		else if (now == scr_time)
			lv_scr_load_anim(scr_temp, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, false);
	}
}

// 状态栏
static void create_status_bar(void)
{
	if (status_bar != NULL)
		return; // 防止重复创建

	status_bar = lv_obj_create(lv_layer_sys()); // 创建状态栏
	lv_obj_set_size(status_bar, 320, 30);		// 设置状态栏大小

	lv_obj_align(status_bar, LV_ALIGN_BOTTOM_MID, 0, 0);						   // 状态栏对齐底部中间
	lv_obj_set_style_bg_color(status_bar, lv_color_hex(back_color), LV_PART_MAIN); // 设置状态栏背景颜色
	lv_obj_set_style_bg_opa(status_bar, LV_OPA_70, LV_PART_MAIN);

	lv_obj_clear_flag(status_bar, LV_OBJ_FLAG_SCROLLABLE); // 状态栏不可滚动

	// 添加时间标签
	time_label = lv_label_create(status_bar);
	lv_obj_align(time_label, LV_ALIGN_RIGHT_MID, 0, 0);
}
// 时间标签刷新
static void rtc_timer_cb(lv_timer_t *t)
{
	RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure); // 获取时间
	RTC_GetDate(RTC_Format_BIN, &RTC_DateStructure); // 获取日期

	sprintf(time_str, "%02d:%02d:%02d",
			RTC_TimeStructure.RTC_Hours,
			RTC_TimeStructure.RTC_Minutes,
			RTC_TimeStructure.RTC_Seconds);

	lv_label_set_text(time_label, time_str);
}
// 温度窗口事件处理函数
static void event_handler_src_tmp(lv_event_t *e)
{
	uint8_t dht11_data[5] = {0}; // 温湿度数据
	int32_t rt;

	lv_event_code_t code = lv_event_get_code(e); // 获取当前事件的代码类型
	lv_obj_t *target = lv_event_get_target(e);	 // 获取当前事件的对象指针
	if (target == btn_get_tmp_hum && code == LV_EVENT_CLICKED)
	{
		// 调用DHT11传感器读取数据函数
		rt = dht11_read_data(dht11_data);
		printf("\r\n温度按钮被点击\n");
		if (rt == 0)
		{
			temperature = dht11_data[2] + dht11_data[3] / 10.0f; // 温度
			humidity = dht11_data[0] + dht11_data[1] / 10.0f;	 // 湿度
			printf("\r\n温度：%.2f 湿度：%.2f\r\n", temperature, humidity);

			lv_label_set_text_fmt(label_dht11_Tdata, "%d.%d", dht11_data[2], dht11_data[3]); // 设置温度数据
			lv_label_set_text_fmt(label_dht11_Hdata, "%d.%d", dht11_data[0], dht11_data[1]); // 设置湿度数据
			lv_bar_set_value(tmp_bar, (int)temperature, LV_ANIM_ON);						 // 设置进度条的值，并启用动画效果
			lv_bar_set_value(hum_bar, (int)humidity, LV_ANIM_ON);							 // 设置进度条的值，并启用动画效果
		}
	}
}

// 创建主窗口
static void scr_main_create()
{
	scr_main = lv_obj_create(NULL);			  // 在当前活动屏幕上创建一个容器对象
	lv_obj_set_size(scr_main, 320, 240);	  // 设置容器大小为320x240
	lv_obj_set_style_pad_all(scr_main, 0, 0); // 内边距设为0

	// 主窗口添加手势事件
	lv_obj_add_event_cb(scr_main, gesture_event_cb, LV_EVENT_GESTURE, NULL);
}

// 初始化温度窗口
static void scr_temp_create()
{
	scr_temp = lv_obj_create(NULL);									  // 创建一个容器对象
	lv_obj_set_size(scr_temp, 320, 240);							  // 设置容器大小为320x240
	lv_obj_set_style_bg_color(scr_temp, lv_color_hex(back_color), 0); // 设置容器背景颜色
	lv_obj_add_event_cb(scr_temp, gesture_event_cb, LV_EVENT_GESTURE, NULL);

	// 刷新数据按钮
	btn_get_tmp_hum = lv_btn_create(scr_temp);
	lv_obj_set_size(btn_get_tmp_hum, 200, 50);								 // 设置大小
	lv_obj_set_pos(btn_get_tmp_hum, 60, 160);								 // 设置位置
	lv_obj_set_style_bg_color(btn_get_tmp_hum, lv_color_hex(back_color), 0); // 设置背景颜色
	lv_obj_t *label_get_val = lv_label_create(btn_get_tmp_hum);				 // 在按钮上创建标签
	lv_obj_set_style_text_color(label_get_val, lv_color_hex(BLUE), 0);		 // 设置标签字体颜色
	lv_label_set_text(label_get_val, "FLASH");								 // 设置标签文本
	lv_obj_center(label_get_val);											 // 将按钮上的标签居中显示
	// 为按钮添加点击事件
	lv_obj_add_event_cb(btn_get_tmp_hum, event_handler_src_tmp, LV_EVENT_CLICKED, NULL);

	// 设置温度进度条
	tmp_bar = lv_bar_create(scr_temp);			  // 创建进度条对象
	lv_obj_set_size(tmp_bar, 200, 30);			  // 设置进度条的大小
	lv_obj_set_pos(tmp_bar, 60, 60);			  // 设置进度条的位置
	lv_bar_set_range(tmp_bar, 0, 100);			  // 设置进度条的范围
	lv_bar_set_mode(tmp_bar, LV_BAR_MODE_NORMAL); // 设置为普通模式
	// 设置湿度进度条
	hum_bar = lv_bar_create(scr_temp);
	lv_obj_set_size(hum_bar, 200, 30);
	lv_obj_set_pos(hum_bar, 60, 120);
	lv_bar_set_range(hum_bar, 0, 100);
	lv_bar_set_mode(hum_bar, LV_BAR_MODE_NORMAL);

	// 在屏幕上创建用于显示DHT11数据的标签
	label_dht11_Tdata = lv_label_create(tmp_bar);
	lv_obj_align(label_dht11_Tdata, LV_ALIGN_RIGHT_MID, 0, 0); // 将标签靠右居中对齐
	label_dht11_Hdata = lv_label_create(hum_bar);
	lv_obj_align(label_dht11_Hdata, LV_ALIGN_RIGHT_MID, 0, 0);

	// 添加温度图像
	LV_IMG_DECLARE(image_Temperature);																  // 声明图像资源
	label_image_Temperature = lv_img_create(scr_temp);												  // 在当前窗口创建图像控件
	lv_obj_set_size(label_image_Temperature, 30, 30);												  // 设置标签大小
	lv_img_set_src(label_image_Temperature, &image_Temperature);									  // 设置图像源
	lv_obj_set_pos(label_image_Temperature, 20, 60);												  // 设置位置
	lv_obj_set_size(label_image_Temperature, image_Temperature.header.w, image_Temperature.header.h); // 设置图像控件大小与图像尺寸一致
	// 添加湿度图像
	LV_IMG_DECLARE(image_Humidity);
	label_image_Humidity = lv_img_create(scr_temp);
	lv_obj_set_size(label_image_Humidity, 30, 30);
	lv_img_set_src(label_image_Humidity, &image_Humidity);
	lv_obj_set_pos(label_image_Humidity, 20, 120);
	lv_obj_set_size(label_image_Humidity, image_Humidity.header.w, image_Humidity.header.h);
}

// 设置时间窗口
static void scr_time_create()
{
	scr_time = lv_obj_create(NULL);									  // 在当前活动屏幕上创建一个容器对象
	lv_obj_set_size(scr_time, 320, 240);							  // 设置容器大小
	lv_obj_set_style_bg_color(scr_time, lv_color_hex(back_color), 0); // 设置容器背景颜色
	lv_obj_set_style_border_width(scr_time, 0, 0);					  // 设置容器边框宽度为0
	lv_obj_set_style_pad_all(scr_time, 0, 0);						  // 内边距设为0
	lv_obj_add_event_cb(scr_time, gesture_event_cb, LV_EVENT_GESTURE, NULL);

	arc = lv_arc_create(scr_time);	   // 在活动屏幕上创建一个弧形对象
	lv_obj_set_size(arc, 150, 150);	   // 设置弧形对象的大小
	lv_arc_set_rotation(arc, 135);	   // 设置弧形对象的旋转角度
	lv_arc_set_bg_angles(arc, 0, 360); // 设置背景弧形的起始和结束角度

	lv_arc_set_range(arc, 0, 3600); // 设置弧形对象的范围值
	lv_arc_set_value(arc, 40);		// 设置弧形对象的当前值
	lv_obj_center(arc);				// 将弧形对象居中显示
}

// 切换主题函数
static void change_theme()
{
	// 重新加载背景颜色
	lv_obj_set_style_bg_color(scr_main, lv_color_hex(back_color), 0);
	lv_obj_set_style_bg_color(scr_temp, lv_color_hex(back_color), 0);
	lv_obj_set_style_bg_color(scr_time, lv_color_hex(back_color), 0);
}

// 主函数
int main(void)
{
	// 硬件初始化
	key_init(); // 按键初始化
	rtc_init(); // 初始化RTC

	usart1_init(115200); // 串口1初始化波特率为115200bps

	// 串口延迟一会，确保芯片内部完成全部初始化,printf无乱码输出
	delay_ms(1000);

	// LVGL初始化
	lv_init();								   // 初始化LVGL库
	lv_port_disp_init();					   // 初始化LVGL显示设备
	lv_port_indev_init();					   // 初始化LVGL输入设备
	lv_timer_create(rtc_timer_cb, 1000, NULL); // 1 秒周期
	tim3_init();							   // tim3初始化，定时周期为1ms

	// UI初始化
	scr_main_create(); // 创建主窗口
	scr_temp_create(); // 创建温度窗口
	scr_time_create(); // 创建时间窗口

	change_theme();		 // 初始化主题
	create_status_bar(); // 创建状态栏

	// 加载第一个屏幕
	lv_scr_load(scr_main);

	printf("\r\n主窗口被加载\r\n");

	while (1)
	{
		lv_task_handler(); // LVGL任务处理
	}

	return 0;
}
