#ifndef SERIALISIMO_H
#define SERIALISIMO_H

#include <QObject>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QColorDialog>
#include <QMediaPlayer>

class Serialisimo : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(qreal valor READ  valor WRITE setvalor NOTIFY valuechanged)
    //Q_PROPERTY(qreal value READ value WRITE setValue NOTIFY valueChanged)
    //Q_PROPERTY(qreal valordimmer READ valordimmer WRITE setvalor)
public:
    explicit Serialisimo(QObject *parent = 0);


    //Q_INVOKABLE void enviarescena(QString color, int numfoco, int estadofoco, int dimmer, int ctocortina, int estadocortina);

      //1 VALOR INSTANTANEO (0) Y 3 ESCENAS (1,2,3)


      //foco 1 estado
    //Q_INVOKABLE int dimmer[3];
    Q_INVOKABLE int vistaprevia;
    Q_INVOKABLE int numescena;  //variable global para numero de escena


    Q_INVOKABLE QString colorRGB[4]={"#ff0000","#ff0000","#0000ff","#000000"}; //se almacenan las escenas

    Q_INVOKABLE int foco1[4];
    Q_INVOKABLE int estadofoco1[4];

    Q_INVOKABLE QString getcolorRGB(int numero);  //color en el arreglo, debe retornar valor

    Q_INVOKABLE QString coloranterior;
    Q_INVOKABLE QString obtenercolor(QString color);  //para guardar color anterior/apagado
    Q_INVOKABLE QString recuperarcolor();//para utilizarlo en QML




    //Q_INVOKABLE char escena1(QString color, int numfoco, int estadofoco, int dimmer, int ctocortina, int estadocortina);
    Q_INVOKABLE void guardar(int escena);//, QString color, int cto, int estado);

    //Q_INVOKABLE char guardado1(QString color);


    Q_INVOKABLE void test();
    //Q_INVOKABLE void iniciarSerial();

    Q_INVOKABLE void apagartodo();
    Q_INVOKABLE void proyeccion();
    Q_INVOKABLE void escenaclases();

    Q_INVOKABLE void enviarfoco(int cto,int estado);
    Q_INVOKABLE void enviarcortina(int cto,int estado);
    Q_INVOKABLE void enviardimmer(int numero);
    Q_INVOKABLE void enviarRGB(QString color);
    Q_INVOKABLE void establecer(int escena);

    //17 julio
    Q_INVOKABLE QString escena1[5]={"#ff0000","0","1","arriba","15"};//RGB,Foco1,Foco2,Cortina,Dimmer
    Q_INVOKABLE QString escena2[5]={"#00ff00","1","0","abajo","50"};//RGB,Foco1,Foco2,Cortina,Dimmer
    Q_INVOKABLE QString escena3[5]={"#0000ff","1","1","arriba","99"};//RGB,Foco1,Foco2,Cortina,Dimmer





   signals:
       qreal valueChanged(int valor);

};



#endif // SERIALISIMO_H
