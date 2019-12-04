#pragma once
/*
*此文件由GUI工具生成
*文件功能：用于处理用户的逻辑相应代码
*功能说明：
*========================onButtonClick_XXXX
当页面中的按键按下后系统会调用对应的函数，XXX代表GUI工具里面的[ID值]名称，
如Button1,当返回值为false的时候系统将不再处理这个按键，返回true的时候系统将会继续处理此按键。比如SYS_BACK.
*========================onSlideWindowItemClick_XXXX(int index) 
当页面中存在滑动窗口并且用户点击了滑动窗口的图标后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如slideWindow1;index 代表按下图标的偏移值
*========================onSeekBarChange_XXXX(int progress) 
当页面中存在滑动条并且用户改变了进度后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如SeekBar1;progress 代表当前的进度值
*========================ogetListItemCount_XXXX() 
当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表的总数目,XXX代表GUI工具里面的[ID值]名称，
如List1;返回值为当前列表的总条数
*========================oobtainListItemData_XXXX(ZKListView::ZKListItem *pListItem, int index)
 当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表当前条目下的内容信息,XXX代表GUI工具里面的[ID值]名称，
如List1;pListItem 是贴图中的单条目对象，index是列表总目的偏移量。具体见函数说明
*========================常用接口===============
*LOGD(...)  打印调试信息的接口
*mTextXXX->setText("****") 在控件TextXXX上显示文字****
*mButton1->setSelected(true); 将控件mButton1设置为选中模式，图片会切换成选中图片，按钮文字会切换为选中后的颜色
*mSeekBar->setProgress(12) 在控件mSeekBar上将进度调整到12
*mListView1->refreshListView() 让mListView1 重新刷新，当列表数据变化后调用
*mDashbroadView1->setTargetAngle(120) 在控件mDashbroadView1上指针显示角度调整到120度
*
* 在Eclipse编辑器中  使用 “alt + /”  快捷键可以打开智能提示
*/

bool bAdd = 0;
int fix = 1;

// 消息监听接口如下
class PlayerMessageListener : public ZKMediaPlayer::IPlayerMessageListener {
public:
    virtual void onPlayerMessage(ZKMediaPlayer *pMediaPlayer, int msg, void *pMsgData) {
        switch (msg) {
        case ZKMediaPlayer::E_MSGTYPE_ERROR_INVALID_FILEPATH:
        case ZKMediaPlayer::E_MSGTYPE_ERROR_MEDIA_ERROR:
            // 出错消息
            break;

        case ZKMediaPlayer::E_MSGTYPE_PLAY_STARTED:
            // 开始播放消息
            break;

        case ZKMediaPlayer::E_MSGTYPE_PLAY_COMPLETED:
            // 播放结束消息
            break;
        }
    }
};
static PlayerMessageListener sPlayerMessageListener;


/*
// 音乐操作接口说明
sMediaPlayerPtr->play("/mnt/extsd/music/test.mp3");	// 播放指定路径的文件
sMediaPlayerPtr->pause();	// 暂停播放
sMediaPlayerPtr->resume();	// 恢复播放
sMediaPlayerPtr->seekTo(int msec);	// 跳转到msec时间播放， msec 单位: ms
sMediaPlayerPtr->stop();	// 停止播放
sMediaPlayerPtr->isPlaying();	// 是否播放中，返回bool型

sMediaPlayerPtr->getDuration();	// 获取当前播放歌曲的总时间
sMediaPlayerPtr->getCurrentPosition();	// 获取当前播放歌曲的当前播放时间点

*/

/**
 * 注册定时器
 * 在此数组中添加即可
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	{0,  20}, //定时器id=0, 时间间隔6秒
	//{1,  1000},
};

static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1->setText("123");
	EASYUICONTEXT->showStatusBar();

	// 创建ZKMediaPlayer对象
	ZKMediaPlayer *sMediaPlayerPtr = new ZKMediaPlayer(ZKMediaPlayer::E_MEDIA_TYPE_AUDIO);

	// 注册消息监听
	sMediaPlayerPtr->setPlayerMessageListener(&sPlayerMessageListener);
	sMediaPlayerPtr->play("/mnt/extsd/music/test.mp3");
}

static void onUI_quit() {
	EASYUICONTEXT->hideStatusBar();
}

static void onProtocolDataUpdate(const SProtocolData &data) {
    // 串口数据回调接口
}
static int angleTab[]={
  0,  0,  0,  0,  1,  3,  6,  8, 12, 16,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80,
 26, 29, 32, 36, 39, 42, 52, 68, 78, 80
};
int angindex = 0;
int sta  =0;
int value = 0;
static bool onUI_Timer(int id){
    //Tips:添加定时器响应的代码到这里,但是需要在本文件的 REGISTER_ACTIVITY_TIMER_TAB 数组中 注册
    //id 是定时器设置时候的标签,这里不要写耗时的操作，否则影响UI刷新,ruturn:[true] 继续运行定时器;[false] 停止运行当前定时器

	if(id == 0){
		if (sta == 0) {
				value = value > 0 ? value - 2 : value;
				if (value <= 21) sta = 1;
		} else if(sta == 1){
				value = (value >= 0 && value < 45) ? value + 3 : value;
				if (value >= 45) sta = 2;
		} else if(sta == 2){
				value = (value >=45 && value < 75)? value + 2 : value;
				if (value >= 75) sta = 3;
		} else if(sta == 3){
				value = value > 55 ? value - 1 : value;
				if (value <= 55) sta = 4;
		} else if(sta == 4){
				value = value < 115 ? value + 1 : value;
				if (value >= 115) sta = 0;
		}
		mPointer1Ptr->setTargetAngle(value);
	}
	return true;
}


static bool ontestpointerActivityTouchEvent(const MotionEvent &ev) {
    // 返回false触摸事件将继续传递到控件上，返回true表示该触摸事件在此被拦截了，不再传递到控件上
    return false;
}
static bool onButtonClick_sys_back(ZKButton *pButton) {
    //LOGD(" ButtonClick sys_back !!!\n");
    return false;
}

