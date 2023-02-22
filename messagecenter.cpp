#include "messagecenter.h"
#include "ui_messagecenter.h"
#include "messagecenteritem.h"


#include <QFile>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonArray>
#include <QFileInfo>

messageCenter::messageCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::messageCenter)
{
    ui->setupUi(this);
    newMessage_ = false;
    //给返回按钮设置图标
    Common::setButtonIcon(ui->goBack,icon::getIcon("return"));
    connect(ui->goBack,&QPushButton::clicked,this,&messageCenter::goBackSlot);
    connect(ui->messageRead,&QPushButton::clicked,this,&messageCenter::messageRead);
    getMessage();
    show();
}

messageCenter::~messageCenter()
{
    delete ui;
}

void messageCenter::goBackSlot()
{
    emit goBackSignal(PB_GO_HOME,0,0,0);
}


void messageCenter::messageRead()
{
    //清空红点
    ui->messageScrollArea->hide();
    for (int i=0;i<messageWidgetList.size();i++) {
        messageWidgetList[i]->read();
    }
    ui->messageScrollArea->show();

    for (int i=0;i<messages_.size();i++) {
        if(messages_[i].status == 0) messages_[i].status = 1;
    }
}

void messageCenter::acceptPush(messageStruct message){
    if(!ids_.contains(message.id)){
        messages_.insert(0,message);
        ids_.append(message.id);
        show();

        saveData();
    }
}

void messageCenter::getMessage(){

    QFileInfo info(":/resource/message.json");
    qDebug() << info.absoluteFilePath();
    qDebug() << info.isWritable();

    QFile file(":/resource/message.json");	//创建QFile对象，并指定json文件路径
    //打开json文件并判断（不成功则返回0）
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"json file load err";
        return;
    }
    //将文件内容读取到数组中
    QByteArray data(file.readAll());
    file.close();	//关闭文件

    QJsonParseError jError;	//创建QJsonParseError对象
    //使用QJsonDocument的fromJson函数读取json串，并将QJsonParseError对象传入获取错误值
    QJsonDocument jDoc = QJsonDocument::fromJson(data, &jError);
    //判断QJsonParseError对象获取的error是否包含错误，包含则返回0
    if(jError.error != QJsonParseError::NoError)
    {
        qDebug()<<"json err";
        return;
    }
    if(!jDoc.isArray()){
        qDebug()<<"json format err";
        return;
    }

    //获取QJsonObject，并读取Json串中各类型的值
    QJsonArray jArray = jDoc.array();
    //将QJsonArray转QVariantList
    QVariantList list = jArray.toVariantList();

    if(list.size()<=0){
        return;
    }
    for(int i=0;i<list.size();i++){
        QVariantMap message = list[i].toMap();
        messageStruct msg;
        if(message.find("id") != message.end()){
            msg.id = message["id"].toInt();
        }
        if(message.find("title") != message.end()){
            msg.title = message["title"].toString();
        }
        if(message.find("date_time") != message.end()){
            msg.dateTime = message["date_time"].toString();
        }
        if(message.find("content") != message.end()){
            msg.content = message["content"].toString();
        }
        if(message.find("icon") != message.end()){
            msg.icon = message["icon"].toString();
        }

        if(message.find("status") != message.end()){
            msg.status = message["status"].toInt();
        }
        if(message.find("type") != message.end()){
            msg.type = message["type"].toInt();
        }
        messages_.append(msg);
    }

}

void messageCenter::show(){
    int messageSize = messages_.size();
    int messageWidgetSize = messageWidgetList.size();
    qDebug()<<__FUNCTION__<<messageSize<<"-"<<messageWidgetSize;
    if(messageWidgetSize<messageSize){
        while(messageSize>messageWidgetSize){
            messageCenterItem* bts = new messageCenterItem(this);
            messageWidgetList.append(bts);
            ui->scrollAreaWidgetContents->layout()->addWidget(bts);
            messageWidgetSize++;
        }
    }

    for (int i=0;i<messageSize;i++) {
        messageCenterItem * message = messageWidgetList[i];
        messageStruct messageS = messages_[i];
        ids_.append(messageS.id);
        message->setData(messageS);
    }
    ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());
}


void messageCenter::saveData(){
//    if(newMessage_){
        QJsonArray list;
        for(int i=0;i<messages_.size();i++){
            QJsonObject m;
            m.insert("id",messages_[i].id);
            m.insert("title",messages_[i].title);
            m.insert("date_time",messages_[i].dateTime);
            m.insert("content",messages_[i].content);
            m.insert("icon",messages_[i].icon);
            m.insert("status",messages_[i].status);
            m.insert("type",messages_[i].type);
            list.append(m);
        }
        QJsonDocument document;
        document.setArray(list);
        QByteArray byte_array = document.toJson(QJsonDocument::Compact);
        QString json_str(byte_array);
        qDebug()<<json_str;

        //保存文件
        QFile file(":/resource/message.json");

        qDebug()<<"file.isOpen()"<<file.isOpen();

        if (!file.open(QIODevice::Truncate | QIODevice::ReadWrite))
        {
            qDebug() << "file error!";
        }

        qDebug()<<"file.isOpen()"<<file.isOpen();
        QTextStream in(&file);
        in << json_str;

        file.close();
//    }
}

