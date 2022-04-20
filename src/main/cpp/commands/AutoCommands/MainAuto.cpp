#include "commands/AutoCommands/MainAuto.h"

MainAuto::MainAuto(WestCoastDrive* p_Drive) : mp_Drive{p_Drive} {
    // NOT SAFE AT ALL
    AddCommands(TurnToAnglePID{mp_Drive, 90_deg});
}