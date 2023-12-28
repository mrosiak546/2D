
#include "projekt2d.h"
#include <QPainter>

projekt2d::projekt2d(QWidget *parent)
    : QWidget{parent}
{
        im = QImage(im_width, im_height, QImage::Format_RGB32);
        im_org.load("C:/Users/rosia/OneDrive/Pulpit/Studia/Grafika Komputerowa/Projekt2D/image.png");
        reset();
}

void projekt2d::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(0, 0, width(), height(), Qt::white);
    p.drawImage(0, 0, im);
}

void projekt2d::mnozenieMacierzy(double macierz1[3][3], double macierz2[3][3])
{
    double wynik[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            wynik[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                wynik[i][j] += macierz1[i][k] * macierz2[k][j];
            }
        }
    }

    // Przypisanie wyniku
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            macierz1[i][j] = wynik[i][j];
        }
    }
}

void projekt2d::kolory(double macierz[3][3]) //interpolacja
{
    im.fill(Qt::white);
    //Przeszukiwanie obrazu
    for(int y = 0; y < im_height; y++)
    {
        for(int x = 0; x < im_width; x++)
        {
            // Przekształcenie współrzędnych piksela za pomocą macierzy
            double newX = macierz[0][0] * x + macierz[0][1] * y + macierz[0][2] * 1; //x po wykonaniu jakiegoś przekształcenia
            double newY = macierz[1][0] * x + macierz[1][1] * y + macierz[1][2] * 1;//y po wykonaniu jakiegoś przekształcenia
            //double newZ = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2]; //to jest zawsze 1
            //std::cout<<newZ<<std::endl;

            // Określenie najbliższych pikseli dla nowych współrzędnych
            int pixelX1 = round(newX);
            int pixelY1 = round(newY);
            int pixelX2 = pixelX1 + 1;
            int pixelY2 = pixelY1 + 1;

            // Sprawdzenie, czy nowe współrzędne mieszczą się w granicach obrazka
            if (pixelX1 >= 0 && pixelX2 < im_width && pixelY1 >= 0 && pixelY2 < im_height)
            {
                // Obliczenie średniej wartości kolorów pikseli
                QRgb color1 = im_org.pixel(pixelX1, pixelY1);
                QRgb color2 = im_org.pixel(pixelX2, pixelY1);
                QRgb color3 = im_org.pixel(pixelX1, pixelY2);
                QRgb color4 = im_org.pixel(pixelX2, pixelY2);

                int red = (qRed(color1) + qRed(color2) + qRed(color3) + qRed(color4)) / 4;
                int green = (qGreen(color1) + qGreen(color2) + qGreen(color3) + qGreen(color4)) / 4;
                int blue = (qBlue(color1) + qBlue(color2) + qBlue(color3) + qBlue(color4)) / 4;

                // Ustawienie koloru piksela na nowych współrzędnych
                im.setPixel(x, y, qRgb(red, green, blue));
            }

        }
    }
}

void projekt2d::operacje()
{
    double macierz1[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    double macierz2[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    //przesuniece do punktu (0,0)
    macierz2[0][2] = im_width/2;
    macierz2[1][2] = im_height/2;
    mnozenieMacierzy(macierz1, macierz2);

    //wykonanie operacji obrocenia, skalowania i pochylenia
    mnozenieMacierzy(macierz1, Skalowanie);
    mnozenieMacierzy(macierz1, Pochylanie);
    mnozenieMacierzy(macierz1, Obracanie);

    //przesuniecie do srodka
    macierz2[0][2] = -im_width/2;
    macierz2[1][2] = -im_height/2;
    mnozenieMacierzy(macierz1, macierz2);

    //rysowanie obrazu
    mnozenieMacierzy(macierz1, Przesuwanie);
    kolory(macierz1);

    update();
}

void projekt2d::przesuwanieDX(int dx)
{
    dx*=-1;
    this->dx=dx;
    Przesuwanie[0][2] = dx;
    Przesuwanie[1][2] = dy;
    operacje();
}
void projekt2d::przesuwanieDY(int dy)
{
    dy*=-1;
    this->dy=dy;
    Przesuwanie[0][2] = dx;
    Przesuwanie[1][2] = dy;
    operacje();
}

void projekt2d::obracanie(int kat)
{
    this->kat=kat;
    double radians = qDegreesToRadians(kat);
    double cosVal = qCos(radians);
    double sinVal = qSin(radians);
    Obracanie[0][0] = cosVal;
    Obracanie[0][1] = -sinVal;
    Obracanie[1][0] = sinVal;
    Obracanie[1][1] = cosVal;
    operacje();
}

void projekt2d::skalowanieSX(int sx_int)
{
    if(!sx_int) return;
    sx=(double)sx_int;
    sx/=100; //dokladnosc bo gdyby int to wartosc bylby 0 lub 1 czy cos w tym stylu i bylby tylko paseczek (zakres od 0 do 2 a my chcemy wartosci z przeicnkiem
    Skalowanie[0][0]=sx;
    Skalowanie[1][1]=sy;
    operacje();
}
void projekt2d::skalowanieSY(int sy_int)
{
    if(!sy_int) return;
    sy=(double)sy_int;
    sy/=100;
    Skalowanie[0][0]=sx;
    Skalowanie[1][1]=sy;
    operacje();
}
void projekt2d::pochylanieSHX(int shx_int)
{
    shx=(double)shx_int;
    shx/=100;
    Pochylanie[0][1] = shx;
    Pochylanie[1][0] = shy;
    operacje();
}
void projekt2d::pochylanieSHY(int shy_int)
{
    shy=(double)shy_int;
    shy/=100;
    Pochylanie[0][1] = shx;
    Pochylanie[1][0] = shy;
    operacje();
}

void projekt2d::reset()
{
    im.fill(Qt::white);
    im = im_org;
    update();
}


