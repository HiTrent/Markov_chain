#ifndef MARKOV_H
#define MARKOV_H
#include <QMainWindow>

namespace Ui {class Markov;}

class Markov : public QMainWindow
{
    Q_OBJECT
    public:explicit Markov(QWidget *parent = nullptr);
    ~Markov();

    private:Ui::Markov *ui;
            int x = 195;

    public slots: void on_pushButton_clicked();
    protected: void paintEvent(QPaintEvent *);
};

#endif // MARKOV_H
