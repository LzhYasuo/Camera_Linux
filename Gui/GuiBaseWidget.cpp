#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>

#include "GuiBaseWidget.h"

GuiBaseWidget::GuiBaseWidget(QWidget *parent)
    :QWidget (parent)
{
    Q_UNUSED(parent);
}

GuiBaseWidget::~GuiBaseWidget()
{

}

QHBoxLayout *GuiBaseWidget::Get_HLayout(int Spaceing, int left, int right, int top, int bottom)
{
    QHBoxLayout* mLayout = new QHBoxLayout();
    mLayout->setSpacing(Spaceing);
    mLayout->setContentsMargins(left,top,right,bottom);

    return mLayout;
}

QVBoxLayout *GuiBaseWidget::Get_VLayout(int Spaceing, int left, int right, int top, int bottom)
{
    QVBoxLayout* mLayout = new QVBoxLayout();
    mLayout->setSpacing(Spaceing);
    mLayout->setContentsMargins(left,top,right,bottom);

    return mLayout;
}

QPushButton *GuiBaseWidget::Get_Button(QString text, int width, int height, QString Style)
{
    QPushButton* btn = new QPushButton();
    btn->setText(text);
    if(width != 0)
        btn->setFixedWidth(width);
    if(height != 0)
        btn->setFixedHeight(height);
    btn->setStyleSheet(Style);

    return btn;
}

QPushButton *GuiBaseWidget::Get_IconButton(QString text, QString icon, int width, int height, int iconWidth, int iconHeight, QString Style)
{
    QPushButton* btn = new QPushButton();
    btn->setText(text);
    btn->setIcon(QIcon(icon));
    if(iconWidth!= 0 && iconHeight != 0)
        btn->setIconSize(QSize(iconWidth,iconHeight));
    if(width != 0)
        btn->setFixedWidth(width);
    if(height != 0)
        btn->setFixedHeight(height);
    btn->setStyleSheet(Style);

    return btn;
}

QLabel *GuiBaseWidget::Get_Label(QString text, int width, int height, QString Style)
{
    QLabel* lbl = new QLabel();
    lbl->setText(text);
    if(width != 0)
        lbl->setFixedWidth(width);
    if(height != 0)
        lbl->setFixedHeight(height);
    lbl->setStyleSheet(Style);

    return lbl;
}

QLabel *GuiBaseWidget::Get_PixLabel(QString pix, int width, int height, QString Style)
{
    QLabel* lbl = new QLabel();
    const QPixmap _pix = pix;
    lbl->setPixmap(pix);
    if(width != 0)
        lbl->setFixedWidth(width);
    if(height != 0)
        lbl->setFixedHeight(height);
    if(width != 0 && height != 0)
        _pix.scaled(width,height);
    lbl->setStyleSheet(Style);

    return lbl;
}

QComboBox *GuiBaseWidget::Get_ComboBox(QStringList List, int width, int height)
{
    QComboBox* box = new QComboBox();
    box->addItems(List);
    if(width != 0)
        box->setFixedWidth(width);
    if(height != 0)
        box->setFixedHeight(height);

    return box;
}
