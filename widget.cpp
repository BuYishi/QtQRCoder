#include "widget.h"
#include "ui_widget.h"
#include "QREncode/qrencode.h"
#include <QPainter>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <QZXing.h>
#include <QtDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_chooseButton_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,"选择");
    qDebug()<<fileName;
    if(!fileName.isEmpty())
    {
        QImage img;
        qDebug()<<img.load(fileName);
        ui->decodedImgLabel->clear();
        ui->decodedImgLabel->setPixmap(QPixmap(fileName));
        QZXing decoder;
        QString result=decoder.decodeImage(img);
        qDebug()<<result;
        ui->resultTextEdit->setText(result);
        qDebug()<<QZXing().decodeImageFromFile(fileName);
    }
}

void Widget::on_saveButton_clicked()
{
    QString fileName=QFileDialog::getSaveFileName(this,"保存");
    if(!fileName.isEmpty())
    {
       if(ui->encodedImgLabel->pixmap()->save(fileName))
           QMessageBox::information(this,"提示","保存成功！");
       else
           QMessageBox::critical(this,"错误","保存失败！错误未知！");
    }
}

void Widget::on_encodeButton_clicked()
{
    QRcode *qrcode = QRcode_encodeString(ui->contentTextEdit->document()->toPlainText().toStdString().c_str(), 7, QR_ECLEVEL_H, QR_MODE_8, 1);
    if(qrcode!=nullptr)
    {
        unsigned char *data = qrcode->data;
        QPixmap qrcodePixmap(300,300);
        QPainter painter(&qrcodePixmap);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor("white"));
        painter.drawRect(0, 0, 300,300);
        double scale = (300- 2.0 * 10) / qrcode->width;
        painter.setBrush(QColor("blue"));
        for (int y = 0; y < qrcode->width; y ++)
        {
            for (int x = 0; x < qrcode->width; x ++)
            {
                if (*data & 1)
                {
                    QRectF r(10 + x * scale, 10 + y * scale, scale, scale);
                    painter.drawRects(&r, 1);
                }
                data ++;
            }
        }
        //qDebug()<<qrcodePixmap.save("tmp.png");
        ui->encodedImgLabel->setPixmap(qrcodePixmap);
        data = NULL;
        QRcode_free(qrcode);
    }
    qrcode = NULL;
}

void Widget::on_Widget_destroyed()
{
    qDebug()<<"The window was destroyed.";
}