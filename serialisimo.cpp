#include <serialisimo.h>
#include <QtSerialPort/QSerialPort>
#include <QtWidgets/QSlider>
#include <QColor>
QSerialPort *serial;
int i=0;

Serialisimo::Serialisimo(QObject *parent) : QObject(parent)
{

    if (i==0)
    {
        serial = new QSerialPort(this);
        serial = new QSerialPort(this);
        serial->setPortName("/dev/ttyAMA0");
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        serial->open(QIODevice::ReadWrite);
        qDebug()<<"serial iniciado";
        i=1;
    }

}




QString Serialisimo::obtenercolor(QString color)
{
    //
    coloranterior=color;
    return coloranterior;

}

QString Serialisimo::recuperarcolor()
{
    return coloranterior;
}


void Serialisimo::test()
{
    //enviarRGB("#ffffff");
    //qDebug()<< "color guardado"<<coloranterior;
    qDebug()<< "Holi, soy C++";
    qDebug()<<"escena numero "<<numescena;
    qDebug()<<"colorRGB[1]"<<colorRGB[1];
    qDebug()<<"colorRGB[2]"<<colorRGB[2];
    qDebug()<<"colorRGB[3]"<<colorRGB[3];
    //qDebug()<<foco1[numescena];
    //qDebug()<<estadofoco1[numescena];
}


void Serialisimo::guardar(int escena)
{
    qDebug()<<"Guardar escena numero "<<escena;
    //GUARDA EN EL ESTADO 1, 2 ó 3 (escena)
    //QString scto = QString::number(cto);

    //colorRGB=color;
    colorRGB[escena]=colorRGB[0];  //guarda el color en el slot temporal 0
    foco1[escena]=1;
    estadofoco1[escena]=1;
    //array[2]=QString::number(estadofoco);

   // bool ok; int prueba=array[2].toInt(&ok,10);  //convertir Qstring a int

    qDebug()<<colorRGB[escena];
    //qDebug()<<foco1[escena];
    //qDebug()<<estadofoco1[escena];

}

void Serialisimo::establecer(int escena)
{
    //qDebug()<<"escena numero "<<escena;
    //int set=escena;
    qDebug()<<"Establecer escena"<<escena;
    enviarRGB(colorRGB[escena]);
    qDebug()<<colorRGB[escena];

}

QString Serialisimo::getcolorRGB(int numero)
{
    //qDebug()<<"escena numero "<<numescena;
    return colorRGB[numero];


}


void Serialisimo::apagartodo()
{
    enviarRGB("#000000");
    enviarfoco(1,0);
    enviarfoco(2,0);
    enviardimmer(0);
    enviarcortina(1,0);

}

void Serialisimo::proyeccion()
{
    //bajar cortina, apagar luces, encender proyector
    enviarRGB("#0000ff");
    enviarfoco(1,255);
    enviarfoco(2,0);
    enviardimmer(100);
    enviarcortina(1,255);

}

void Serialisimo::escenaclases()
{

    //subir cortina, prender luces, apagar poyector
    enviarRGB("#ff0000");
    enviarfoco(1,255);
    enviarfoco(2,255);
    enviardimmer(36);
    enviarcortina(1,0);
}




void Serialisimo::enviarfoco(int cto,int estado)
{

    unsigned char rf_maskDim[26]={126, 0, 22, 16, 1, 0x00, 0x13, 0xA2, 0x00, 0x40, 0xC0, 0xE4, 0x02, 0xFF, 0xFE, 0, 0, 'S', 0, 0, 0, 0, 0, 0, 0, 0};  //DIMMER nuevo

    #define buf_size 60
    unsigned char bufferTX[buf_size]; //numbytestosend;
    unsigned char rf_send[8]={'S', 0x01, 0, 0, 0, 0, 0, 0};

    rf_send[1]=cto;
    rf_send[2]=estado;
    unsigned char i, chs=0;
    for (i=0; i<17; i++)
        bufferTX[i]=rf_maskDim[i];
    for (i=17; i<25; i++)
        bufferTX[i]=rf_send[i-17];
    for (i=3; i<25; i++)
        chs+=bufferTX[i];
    bufferTX[25]=255-chs;

    QByteArray databuf((char*)bufferTX, 26);
    QByteArray a(databuf.toHex());
    QByteArray bytes= QByteArray::fromHex(a);
    serial->write(bytes);
    //qDebug()<<bytes;
    qDebug()<<"Foco "<<a;


}

void Serialisimo::enviarcortina(int cto, int estado)
{
    unsigned char rf_maskDim[26]={126, 0, 22, 16, 1, 0x00, 0x13, 0xA2, 0x00, 0x40, 0xC0, 0xE4, 0x18, 0xFF, 0xFE, 0, 0, 'S', 0, 0, 0, 0, 0, 0, 0, 0};  //DIMMER nuevo

    #define buf_size 60
    unsigned char bufferTX[buf_size]; //numbytestosend;
    unsigned char rf_send[8]={'S', 0x01, 0, 0, 0, 0, 0, 0};

    rf_send[1]=cto;
    rf_send[2]=estado;
    unsigned char i, chs=0;
    for (i=0; i<17; i++)
        bufferTX[i]=rf_maskDim[i];
    for (i=17; i<25; i++)
        bufferTX[i]=rf_send[i-17];
    for (i=3; i<25; i++)
        chs+=bufferTX[i];
    bufferTX[25]=255-chs;

    QByteArray databuf((char*)bufferTX, 26);
    QByteArray a(databuf.toHex());
    QByteArray bytes= QByteArray::fromHex(a);
    serial->write(bytes);
    //qDebug()<<bytes;
    qDebug()<<"Cortina "<<a;

}

void Serialisimo::enviardimmer(int numero)
{
        if (numero==100){numero=99;}
        //metodo final

        unsigned char rf_maskDim[26]={126, 0, 22, 16, 1, 0x00, 0x13, 0xA2, 0x00, 0x40, 0xE9, 0x46, 0xBC, 0xFF, 0xFE, 0, 0, 'S', 0, 0, 0, 0, 0, 0, 0, 0};  //DIMMER nuevo

        #define buf_size 60
        unsigned char bufferTX[buf_size]; //numbytestosend;
        unsigned char rf_send[8]={'S', 0x01, 0, 0, 0, 0, 0, 0};

        rf_send[2]=numero;
        unsigned char i, chs=0;
        for (i=0; i<17; i++)
            bufferTX[i]=rf_maskDim[i];
        for (i=17; i<25; i++)
            bufferTX[i]=rf_send[i-17];
        for (i=3; i<25; i++)
            chs+=bufferTX[i];
        bufferTX[25]=255-chs;

        QByteArray databuf((char*)bufferTX, 26);
        QByteArray a(databuf.toHex());
        QByteArray bytes= QByteArray::fromHex(a);
        serial->write(bytes);
        //qDebug()<<bytes;
        qDebug()<<"Dimmer"<<a;


}

void Serialisimo::enviarRGB(QString color)
{
    //qDebug()<<vistaprevia;
    //if(vistaprevia==1)
    {
        colorRGB[0]=color;

        bool ok;
        int red= color.QString::mid(1,2).toInt(&ok,16);  //.toInt()
        //qDebug()<<"red"<<red;
        int green= color.QString::mid(3,2).toInt(&ok,16);  //.toInt()
        //qDebug()<<"green"<<green;
        int blue= color.QString::mid(5,2).toInt(&ok,16);  //.toInt()
        //qDebug()<<"blue"<<blue;



        unsigned char rf_maskDim[26]={126, 0, 22, 16, 1, 0x00, 0x13, 0xA2, 0x00, 0x40, 0xCA, 0xAE, 0x94, 0xFF, 0xFE, 0, 0, 'S', 0, 0, 0, 0, 0, 0, 0, 0};  //DIMMER nuevo

        #define buf_size 60
        unsigned char bufferTX[buf_size]; //numbytestosend;
        unsigned char rf_send[8]={'S', 0x01, 0, 0, 0, 0, 0, 0};

        //rf_send[2]=numero;
        rf_send[3]=red;
        rf_send[4]=green;
        rf_send[5]=blue;
        unsigned char i, chs=0;
        for (i=0; i<17; i++)
            bufferTX[i]=rf_maskDim[i];
        for (i=17; i<25; i++)
            bufferTX[i]=rf_send[i-17];
        for (i=3; i<25; i++)
            chs+=bufferTX[i];
        bufferTX[25]=255-chs;

        QByteArray databuf((char*)bufferTX, 26);
        QByteArray a(databuf.toHex());
        QByteArray bytes= QByteArray::fromHex(a);
        serial->write(bytes);
        //qDebug()<<bytes;
        qDebug()<<"RGB: "<<a;


    }





}









