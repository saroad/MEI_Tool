#ifndef IMAGEBUILDER_H
#define IMAGEBUILDER_H

#include <QtGui/QLabel>
#include <QThread>
#include <QObject>

class ImageBuilder : public QObject{

	Q_OBJECT

public:
	ImageBuilder();
	~ImageBuilder();

public slots:
	void getThreadId(const QImage& preview, bool latexerror);

signals:
	void giveThreadId(const QImage& preview, QString threadId);


};

#endif