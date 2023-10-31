#pragma once

enum Page {
    MENU,
    NEW_GAME,
    CONTINUE,
    SETTINGS,
    STORE,
    INSTRUCTIONS,
    LEADER_BOARDS,
    QUIT,
    PAUSE,
};

namespace CurrentState {
    extern Page currentPage;
    extern bool isPaused;
}