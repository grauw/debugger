#ifndef INTERACTIVELABEL
#define INTERACTIVELABEL

#include <QLabel>

class InteractiveLabel : public QLabel
{
	Q_OBJECT
public:
	InteractiveLabel(QWidget* parent = 0);

protected:
	virtual void enterEvent(QEvent* event);
	virtual void leaveEvent(QEvent* event);

signals:
	void mouseOver(bool state);

public slots:
	void highlight(bool state);
};

#endif // INTERACTIVELABEL
