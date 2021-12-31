#ifndef _GUI_BASE_WIDGET_H_
#define _GUI_BASE_WIDGET_H_

#include <QWidget>

class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class QComboBox;
class GuiBaseWidget : public QWidget
{
    Q_OBJECT
public:
    GuiBaseWidget(QWidget* parent = nullptr);
    ~GuiBaseWidget();

protected:
    //����
    //Spaceing �ռ�֮��ļ�� | left ��߾� | right �ұ߾� | top �ϱ߾� | bottom �±߾�
    QHBoxLayout* Get_HLayout(int Spaceing = 0,int left = 0,int right = 0,int top = 0,int bottom = 0);
    QVBoxLayout* Get_VLayout(int Spaceing = 0,int left = 0,int right = 0,int top = 0,int bottom = 0);

    //��ť
    //text ���� | width ��� | height ���� | Style ��ʽ�� | Icon ͼ�� | IconWidth ͼ���� | IconHeight ͼ�곤��
    QPushButton* Get_Button(QString text = "",int width = 0,int height = 0,QString Style = "");
    QPushButton* Get_IconButton(QString text = "",QString Icon = "",int width = 0,int height = 0,int IconSize = 0,int Iconheight = 0,QString Style = "");

    //��ǩ
    //text ���� | width ��� | height ���� | Style ��ʽ�� | pix ͼƬ
    QLabel* Get_Label(QString text = "",int width = 0,int height = 0,QString Style = "");
    QLabel* Get_PixLabel(QString pix = "",int width = 0,int height = 0,QString Style = "");

    QComboBox* Get_ComboBox(QStringList List = QStringList(),int width = 0,int height = 0);
};

#endif //_GUI_BASE_WIDGET_H_
