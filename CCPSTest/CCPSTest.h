#pragma once

#include <QWidget>
#include "CCPS/CCPSManager.h"
#include "ShowMsg/ShowMsg.h"
#include "NewConnect/NewConnect.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CCPSTest; }
QT_END_NAMESPACE

class CCPSTest : public QWidget {
Q_OBJECT

public:
    explicit CCPSTest(QWidget * = nullptr);

    ~CCPSTest() override;

private:
    Ui::CCPSTest *ui{};
    CCPSManager *ccpsManager = nullptr;
    NewConnect *newConnect = nullptr;

    void bind();

    void enableOperateBtn();

    void connected(CCPS *);

    void showMsg();

    void closeConnect();

    void disconnected();

    void appendLog(const QString &);

    void connectFail(const QHostAddress &, unsigned short, const QByteArray &);

    void toConnect(const QByteArray &, unsigned short);

    QMap<QString, ShowMsg *> connectList;

    void closeEvent(QCloseEvent *) override;
};