import QtQuick 2.7
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.2
import QtQml 2.2

Page1Form {
    width: 800
    height: 480
    checkvistaprevia.onClicked: {
        if(checkvistaprevia.checked)
        {
            serialito.vistaprevia=1.0;
            console.log("vistaprevia"+serialito.vistaprevia);

        }
        else
        {//console.log("vistaprevia desactivada");
            serialito.vistaprevia=0;
            console.log("vistaprevia"+serialito.vistaprevia);

        }
}
    botonestablecer.onClicked: {

        serialito.establecer(serialito.numescena);

        colorseleccionado.color = serialito.getcolorRGB(serialito.numescena);

}
    botonguardar.onClicked: {
        serialito.guardar(serialito.numescena);

}



    botonapagartodo.onClicked: {serialito.numescena=3;
    colorseleccionado.color = serialito.getcolorRGB(3);
    console.log(serialito.getcolorRGB(3));
    }

    botonproyeccion.onClicked: {serialito.numescena=2;
    colorseleccionado.color = serialito.getcolorRGB(2);
    console.log(serialito.getcolorRGB(2));
    }

    botonclases.onClicked:     {
        serialito.numescena=1;
        colorseleccionado.color = serialito.getcolorRGB(1);
        console.log(serialito.getcolorRGB(1));
    }


    botonvariable.onClicked: {
}
    botontest.onClicked: {
        //serialito.guardar(2,"abcdef",1,255);
        serialito.test();
        console.log("test");
        activateScreen();

}

    colorseleccionado.onColorChanged: {

        if(colorseleccionado.color=="#000000")
        {switchapagar.checked= false;}
        else
        {switchapagar.checked= true;
            serialito.obtenercolor(colorseleccionado.color);

        }

        serialito.enviarRGB(colorseleccionado.color);
    }



    botonarriba.onClicked: {
        serialito.enviarcortina(1,255);

}
    botonabajo.onClicked: {
        serialito.enviarcortina(1,0);

    }
    switchDelegate1.onClicked: {
        if(switchDelegate1.checked)
        {serialito.enviarfoco(2,255);}
        else
        {serialito.enviarfoco(2,0);}

}
    switchDelegate.onClicked: {

        if(switchDelegate.checked)
        {serialito.enviarfoco(1,255);}
        else
        {serialito.enviarfoco(1,0);}
}



    areaselectRGB.onClicked: {

        colorDialog.open();
}

    switchapagar.onClicked: {
        if(switchapagar.checked)
        {//console.log("checked");
            colorseleccionado.color = serialito.recuperarcolor();
            //serialito.enviarRGB("#000000");
        }
        else
        {//console.log("no checked");
            colorseleccionado.color = "#000000"
            serialito.enviarRGB("#000000");
        }
}




//DIAL

    dial.onPositionChanged: {porcentaje.text=((dial.position*100).toFixed(0));}


    dial.onValueChanged: {serialito.enviardimmer(dial.value*100);}


}
