#include "widget.h"
#include <QZXing.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
#include <QtDebug>
#include "QREncode/qrencode.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_chooseButton_clicked() {
  const QString &fileName = QFileDialog::getOpenFileName(this, "选择");
  qDebug() << "fileName: " << fileName;
  if (!fileName.isEmpty()) {
    ui->decodedImgLabel->setPixmap(QPixmap(fileName));
    ui->resultTextEdit->setText(QZXing().decodeImageFromFile(fileName));
  }
}

void Widget::on_saveButton_clicked() {
  QString fileName = QFileDialog::getSaveFileName(this, "保存");
  if (!fileName.isEmpty()) {
    if (ui->encodedImgLabel->pixmap()->save(fileName))
      QMessageBox::information(this, "提示", "保存成功！");
    else
      QMessageBox::critical(this, "错误", "保存失败！错误未知！");
  }
}

void Widget::on_encodeButton_clicked() {
  const QImage &barcode =
      QZXing::encodeData(ui->contentTextEdit->document()->toPlainText());
  ui->encodedImgLabel->setPixmap(QPixmap::fromImage(barcode));
}

void Widget::on_Widget_destroyed() {
  qDebug() << "on_Widget_destroyed() called";
}
