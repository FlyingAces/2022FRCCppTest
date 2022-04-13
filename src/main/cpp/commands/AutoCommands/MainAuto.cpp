#include "commands/AutoCommands/MainAuto.h"

MainAuto::MainAuto(WestCoastDrive* p_Drive) : mp_Drive{p_Drive} {
    AddCommands(TurnFor(mp_Drive, 280));
}