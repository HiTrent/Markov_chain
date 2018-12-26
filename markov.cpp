#include "markov.h"
#include "ui_markov.h"
#include <QPainter>
#include <time.h>
#include <unistd.h>

Markov::Markov(QWidget *parent): QMainWindow(parent), ui(new Ui::Markov)
{
    ui->setupUi(this);
    QPalette pal = this -> palette();
    pal.setColor(this -> backgroundRole(), Qt::white);
    this -> setPalette(pal);
    this -> setFixedSize(400, 400);
}

Markov::~Markov() {delete ui;}

void Markov::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(QPen(Qt::black, 1, Qt::SolidLine));

    p.drawText(345, 185, "x"); //X-line
    p.drawLine(50, 165, 350, 165);
    p.drawLine(350, 165, 340, 170);
    p.drawLine(350, 165, 340, 160);

    p.drawText(182, 22, "y"); //Y-line
    p.drawLine(200, 15, 200, 315);
    p.drawLine(200, 15, 205, 25);
    p.drawLine(200, 15, 195, 25);

    for(int i = 50, j = -10; i < 350; i += 15, j++) //Marking of axes
    {
        p.drawLine(i, 170, i, 160);
        p.drawLine(205, i - 20, 195, i - 20);

        if (j != -10 && j != 0)
        {
            p.drawText(i - 3, 185, QString::number(j));
            p.drawText(182, i - 30, QString::number(j * -1));
        }
    }

    p.setBrush(Qt::red);
    p.setPen(QPen(Qt::red, 1, Qt::SolidLine));
    p.drawEllipse(x, 160, 10, 10);
}

void Markov::on_pushButton_clicked()
{
    QString str = ui->lineEdit -> text();
    int n = str.toInt();

    for(int i = 0; i < n; i++)
    {
        sleep(1);
        srand(time(0));
        bool coin = rand() % 2;
        if(coin) x += 15;
        else x -= 15;
        this -> repaint();
        QCoreApplication::processEvents();
    }
}
