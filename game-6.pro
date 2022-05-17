QT += gui widgets

CONFIG += c++11
CONFIG += console

RESOURCES += \
    src/recources.qrc

HEADERS += \
    src/defines.h \
    src/Player/params.h \
    src/Player/player.h \
    src/Player/States/istate.h \
    src/Player/States/Immune/stateimmune.h \
    src/Player/States/Normal/statenormal.h \
    src/Iterator/IteratorBlock/iteratorblock.h \
    src/Iterator/iiterator.h \
    src/gui/canvas/canvas.h \
    src/gui/window/window.h \
    src/game_objects/ifactory.h \
    src/game_objects/igameobject.h \
    src/game_objects/YellowMushroom/mushroomfactory.h \
    src/game_objects/YellowMushroom/yellowmushroom.h \
    src/game_objects/PurpleMushroom/purplemushroom.h \
    src/game_objects/Exit/exit.h \
    src/game_objects/Entrance/entrance.h \
    src/game_objects/DungeonFactory/dungeonfactory.h \
    src/game_objects/ChestRange/chestrange.h \
    src/game_objects/ChestLim/chestlim.h \
    src/game_objects/Bonus/bonus.h \
    src/Field/field.h \
    src/Cell/cell.h \
    src/Observer/Publisher/ipublisher.h \
    src/Observer/Subscriber/isubscriber.h \
    src/Logger/logger.h \
    src/Logger/iloggerimplementation.h \
    src/Logger/Implementations/consolelogimpl.h \
    src/Logger/Implementations/filelogimpl.h \
    src/gui/icommand.h \
    src/gui/commands/commandmove.h \
    src/gui/menu/startmenu.h \
    src/gui/commands/commandfinish.h \
    src/gui/window/States/iwindowstate.h \
    src/gui/window/States/windowstatestart.h \
    src/gui/window/States/windowstateplayer.h \
    src/Enemy/enemy.h \
    src/gui/window/States/windowstateenemy.h \
    src/Enemy/dirs.h \
    src/gui/window/Memento/imemento.h \
    src/gui/window/Memento/memento.h \
    src/gui/window/SaveLoad/saveloadhandler.h \
    src/gui/window/SaveLoad/filewriter.h \
    src/gui/window/SaveLoad/filereader.h \
    src/gui/window/SaveLoad/Exceptions/recogniseerror.h \
    src/gui/window/SaveLoad/Exceptions/readerror.h \
    src/gui/window/SaveLoad/Exceptions/openerror.h

SOURCES += \
    src/main.cpp \
    src/Player/params.cpp \
    src/Player/player.cpp \
    src/Player/States/istate.cpp \
    src/Player/States/Immune/stateimmune.cpp \
    src/Player/States/Normal/statenormal.cpp \
    src/Iterator/IteratorBlock/iteratorblock.cpp \
    src/Iterator/iiterator.cpp \
    src/gui/canvas/canvas.cpp \
    src/gui/window/window.cpp \
    src/game_objects/ifactory.cpp \
    src/game_objects/igameobject.cpp \
    src/game_objects/YellowMushroom/mushroomfactory.cpp \
    src/game_objects/YellowMushroom/yellowmushroom.cpp \
    src/game_objects/PurpleMushroom/purplemushroom.cpp \
    src/game_objects/Exit/exit.cpp \
    src/game_objects/Entrance/entrance.cpp \
    src/game_objects/DungeonFactory/dungeonfactory.cpp \
    src/game_objects/ChestRange/chestrange.cpp \
    src/game_objects/ChestLim/chestlim.cpp \
    src/game_objects/Bonus/bonus.cpp \
    src/Field/field.cpp \
    src/Cell/cell.cpp \
    src/Observer/Publisher/ipublisher.cpp \
    src/Observer/Subscriber/isubscriber.cpp \
    src/Logger/logger.cpp \
    src/Logger/iloggerimplementation.cpp \
    src/Logger/Implementations/consolelogimpl.cpp \
    src/Logger/Implementations/filelogimpl.cpp \
    src/gui/icommand.cpp \
    src/gui/commands/commandmove.cpp \
    src/gui/menu/startmenu.cpp \
    src/gui/commands/commandfinish.cpp \
    src/gui/window/States/iwindowstate.cpp \
    src/gui/window/States/windowstatestart.cpp \
    src/gui/window/States/windowstateplayer.cpp \
    src/Enemy/enemy.cpp \
    src/gui/window/States/windowstateenemy.cpp \
    src/gui/window/Memento/memento.cpp \
    src/gui/window/SaveLoad/saveloadhandler.cpp \
    src/gui/window/SaveLoad/filewriter.cpp \
    src/gui/window/SaveLoad/filereader.cpp \
    src/gui/window/SaveLoad/Exceptions/recogniseerror.cpp \
    src/gui/window/SaveLoad/Exceptions/readerror.cpp \
    src/gui/window/SaveLoad/Exceptions/openerror.cpp
