cmake_minimum_required(VERSION 3.14)

# hide warnings
add_definitions(-w)

# Project specific target properties

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

project(real-time-atari LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(ale test.cpp)
find_package(ZLIB REQUIRED)
add_subdirectory(src)
add_subdirectory(extern/pybind11)
include_directories(extern/pybind11/include/pybind11)

find_package(Threads REQUIRED)

pybind11_add_module(RealtimeAtari
  include/ale_interface.hpp
  include/agent_interface.h
  src/agent_interface.cpp
  src/environment/stella_environment.cpp
  src/environment/phosphor_blend.cpp
  src/environment/ale_state.cpp
  src/environment/stella_environment_wrapper.cpp
  src/pybind_interface.cpp
  src/ale_interface.cpp
  src/agent_interface.cpp
  src/common/SoundExporter.cpp
  src/common/Log.cpp
  src/common/SDL2.cpp
  src/common/Constants.cpp
  src/common/ColourPalette.cpp
  src/common/DynamicLoad.cpp
  src/common/ScreenSDL.cpp
  src/common/ScreenExporter.cpp
  src/games/supported/KeystoneKapers.cpp
  src/games/supported/Boxing.cpp
  src/games/supported/WizardOfWor.cpp
  src/games/supported/MiniatureGolf.cpp
  src/games/supported/Tennis.cpp
  src/games/supported/StarGunner.cpp
  src/games/supported/Zaxxon.cpp
  src/games/supported/VideoPinball.cpp
  src/games/supported/Crossbow.cpp
  src/games/supported/SpaceInvaders.cpp
  src/games/supported/LostLuggage.cpp
  src/games/supported/Casino.cpp
  src/games/supported/Enduro.cpp
  src/games/supported/FishingDerby.cpp
  src/games/supported/Solaris.cpp
  src/games/supported/VideoCube.cpp
  src/games/supported/ElevatorAction.cpp
  src/games/supported/Skiing.cpp
  src/games/supported/Centipede.cpp
  src/games/supported/JamesBond.cpp
  src/games/supported/Tutankham.cpp
  src/games/supported/Galaxian.cpp
  src/games/supported/Assault.cpp
  src/games/supported/Krull.cpp
  src/games/supported/JourneyEscape.cpp
  src/games/supported/Frostbite.cpp
  src/games/supported/MsPacman.cpp
  src/games/supported/Breakout.cpp
  src/games/supported/Hero.cpp
  src/games/supported/Klax.cpp
  src/games/supported/Entombed.cpp
  src/games/supported/Kingkong.cpp
  src/games/supported/YarsRevenge.cpp
  src/games/supported/Earthworld.cpp
  src/games/supported/KungFuMaster.cpp
  src/games/supported/Asteroids.cpp
  src/games/supported/TimePilot.cpp
  src/games/supported/FlagCapture.cpp
  src/games/supported/BankHeist.cpp
  src/games/supported/Frogger.cpp
  src/games/supported/MontezumaRevenge.cpp
  src/games/supported/VideoCheckers.cpp
  src/games/supported/BeamRider.cpp
  src/games/supported/Surround.cpp
  src/games/supported/SpaceWar.cpp
  src/games/supported/Asterix.cpp
  src/games/supported/CrazyClimber.cpp
  src/games/supported/Alien.cpp
  src/games/supported/Carnival.cpp
  src/games/supported/Blackjack.cpp
  src/games/supported/DarkChambers.cpp
  src/games/supported/RiverRaid.cpp
  src/games/supported/HumanCannonball.cpp
  src/games/supported/RoboTank.cpp
  src/games/supported/Freeway.cpp
  src/games/supported/DemonAttack.cpp
  src/games/supported/Atlantis.cpp
  src/games/supported/NameThisGame.cpp
  src/games/supported/Phoenix.cpp
  src/games/supported/PrivateEye.cpp
  src/games/supported/Koolaid.cpp
  src/games/supported/RoadRunner.cpp
  src/games/supported/BattleZone.cpp
  src/games/supported/ChopperCommand.cpp
  src/games/supported/Trondead.cpp
  src/games/supported/Pitfall2.cpp
  src/games/supported/WordZapper.cpp
  src/games/supported/IceHockey.cpp
  src/games/supported/MrDo.cpp
  src/games/supported/SirLancelot.cpp
  src/games/supported/HauntedHouse.cpp
  src/games/supported/Seaquest.cpp
  src/games/supported/AirRaid.cpp
  src/games/supported/VideoChess.cpp
  src/games/supported/Superman.cpp
  src/games/supported/Tetris.cpp
  src/games/supported/Et.cpp
  src/games/supported/TicTacToe3d.cpp
  src/games/supported/DoubleDunk.cpp
  src/games/supported/Kaboom.cpp
  src/games/supported/Pooyan.cpp
  src/games/supported/Hangman.cpp
  src/games/supported/Defender.cpp
  src/games/supported/DonkeyKong.cpp
  src/games/supported/QBert.cpp
  src/games/supported/LaserGates.cpp
  src/games/supported/UpNDown.cpp
  src/games/supported/Amidar.cpp
  src/games/supported/Gopher.cpp
  src/games/supported/Venture.cpp
  src/games/supported/Bowling.cpp
  src/games/supported/Pitfall.cpp
  src/games/supported/Pong.cpp
  src/games/supported/Pacman.cpp
  src/games/supported/Gravitar.cpp
  src/games/supported/Adventure.cpp
  src/games/supported/Backgammon.cpp
  src/games/supported/BasicMath.cpp
  src/games/supported/Berzerk.cpp
  src/games/supported/Turmoil.cpp
  src/games/supported/Othello.cpp
  src/games/supported/Kangaroo.cpp
  src/games/supported/Atlantis2.cpp
  src/games/supported/MarioBros.cpp
  src/games/RomUtils.cpp
  src/games/Roms.cpp
  src/games/RomSettings.cpp
  src/emucore/CartMB.cxx
  src/emucore/CartFASC.cxx
  src/emucore/Paddles.cxx
  src/emucore/CartUA.cxx
  src/emucore/CartE0.cxx
  src/emucore/CartCV.cxx
  src/emucore/Settings.cxx
  src/emucore/Joystick.cxx
  src/emucore/Cart2K.cxx
  src/emucore/Cart0840.cxx
  src/emucore/M6532.cxx
  src/emucore/Switches.cxx
  src/emucore/Cart3F.cxx
  src/emucore/CartF8.cxx
  src/emucore/Device.cxx
  src/emucore/Event.cxx
  src/emucore/CartF8SC.cxx
  src/emucore/CartE7.cxx
  src/emucore/Cart4K.cxx
  src/emucore/CartF6.cxx
  src/emucore/OSystem.cxx
  src/emucore/Console.cxx
  src/emucore/Control.cxx
  src/emucore/CartFE.cxx
  src/emucore/Serializer.cxx
  src/emucore/Props.cxx
  src/emucore/M6502Low.cxx
  src/emucore/Cart4A50.cxx
  src/emucore/CartAR.cxx
  src/emucore/TIA.cxx
  src/emucore/TIASnd.cxx
  src/emucore/M6502.cxx
  src/emucore/CartMC.cxx
  src/emucore/MD5.cxx
  src/emucore/MediaSrc.cxx
  src/emucore/System.cxx
  src/emucore/CartF4SC.cxx
  src/emucore/Cart3E.cxx
  src/emucore/PropsSet.cxx
  src/emucore/CartF4.cxx
  src/emucore/CartDPC.cxx
  src/emucore/Cart.cxx
  src/emucore/Random.cxx
  src/emucore/Deserializer.cxx
  src/emucore/CartF6SC.cxx
  src/emucore/M6502Hi.cxx
  src/emucore/NullDev.cxx
  src/common/SoundSDL.cxx
  src/common/SoundNull.cxx
  src/pybind_interface.cpp)

target_link_libraries(RealtimeAtari
        PUBLIC
        ZLIB::ZLIB
        Threads::Threads dl)

target_link_libraries(ale
        PUBLIC
        ZLIB::ZLIB
        Threads::Threads dl)
