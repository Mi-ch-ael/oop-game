#include <QApplication>

#include "src/gui/window/window.h"

int main(int c, char** v){
    QApplication app(c, v);

    Window window;
    window.show();

    return app.exec();
}
