
#ifndef QT_MPLAYER_H
#define QT_MPLAYER_H

#include <QDialog>
#include <QIcon>
#include <QProcess>
#include <QSlider>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <qtimer.h>
#include <QHBoxLayout>

class m_QWidget : public QWidget
{
    Q_OBJECT
public:
    m_QWidget(QWidget *parent = 0);
    ~m_QWidget();

  bool event(QEvent *e);


signals:
    void doubleclick();

};



class QtMPlayer : public QWidget
{
	Q_OBJECT

public:
	enum PlayState{Playing, Paused, Stopped};

    QtMPlayer(QWidget *parent = 0);
	~QtMPlayer();

	void closeEvent(QCloseEvent *event);

private:
    m_QWidget *videoWidget;
	QPushButton *openButton;
	QPushButton *playButton;
	QIcon playIcon;
	QIcon pauseIcon;
	QPushButton *stopButton;
	QPushButton *slowSpeedButton;
	QPushButton *highSpeedButton;
	QPushButton *frameStepButton;
	QPushButton *muteButton;
    QPushButton *maxButton;
	QSlider *volumeSlider;
	QSlider *seekSlider;
	QProcess *process;
	QTimer *poller;
	QLabel *timeLabel;



	PlayState playState;
    QTextEdit *outEdit;
	float m_speed;
	bool m_bMute;
	bool m_bFrameStep;
	float m_maxTime;
	float m_curTime;
	QString m_fileName;
	int m_volume;

	QString m_stotalTime;
	QString m_scurTime;

	void updateUi();
	QString convertToTime(int secs);

    bool maxFull;
    QVBoxLayout *mainLayout;
    QHBoxLayout *layout;
    QHBoxLayout *btnsLayout;
    QHBoxLayout *timeLayout;

private slots:
	void openFile();
	void startPlay();
	void stopPlay();
	void playOrPause();
	void slowSpeed();
	void highSpeed();
	void frameStep();
	void mute();
	void setVolume(int volume);
	void seekSliderChanged(int pos);
	void pollCurrentTime();
	void mplayerEnded(int exitCode, QProcess::ExitStatus exitStatus);
	void messageProcessing();
    void maxPlay();

};

#endif // QT_MPLAYER_H

