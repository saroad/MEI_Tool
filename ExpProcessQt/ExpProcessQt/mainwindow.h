#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>
#include "klfbackend.h"
#include "klfpreviewbuilderthread.h"

#include "IO_Center.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    //void updatePreviewBuilderThreadInput();
    void showRealTimePreview(const QImage& preview, bool latexerror);
    void copyToClipboard();
	void sendToProcess();

private:
    Ui::MainWindow *ui;
    KLFPreviewBuilderThread *mPreviewBuilderThread;
    KLFBackend::klfInput input;
    KLFBackend::klfSettings settings;
    //KLFBackend::klfOutput output;
    QClipboard *clipboard;
    QPixmap pixmap;
	IO_Center *hub;
	void showSuggestions(QString suggesstion);
};

#endif // MAINWINDOW_H
