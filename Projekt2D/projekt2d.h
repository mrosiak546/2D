
#ifndef PROJEKT2D_H
#define PROJEKT2D_H


#include <QWidget>


class projekt2d : public QWidget
{
    Q_OBJECT
public:
    explicit projekt2d(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);
    void reset();
private:
    QImage im;
    QImage im_org;
    int im_width = 500;
    int im_height = 500;
    double dx=0, dy=0, sx=1, sy=1, shx=0, shy=0, kat=0;

    //Macierze startowe do Przesuwania Skalowania Pochylania Obracania
    double Przesuwanie[3][3]= {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    double Obracanie[3][3]= {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    double Skalowanie[3][3]= {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    double Pochylanie[3][3]= {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    void mnozenieMacierzy(double macierz1[3][3],double macierz2[3][3]);
    void kolory(double macierz[3][3]);
    void operacje();

public slots:
    void przesuwanieDX(int dx);
    void przesuwanieDY(int dy);
    void obracanie(int kat);
    void skalowanieSX(int sx_int);
    void skalowanieSY(int sy_int);
    void pochylanieSHX(int shx_int);
    void pochylanieSHY(int shy_int);


signals:

};

#endif // PROJEKT2D_H
