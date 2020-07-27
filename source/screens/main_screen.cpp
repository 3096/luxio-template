#include "main_screen.hpp"

#include "../theme.hpp"

MainScreen MainScreen::s_instance;

MainScreen::MainScreen() : LOGCONSTRUCT m_basicScreen() {
    lv_obj_t* p_window = theme::createWindow(getLvScreenObj());
    m_basicScreen.addLvObjPositionUpdater(p_window, lx::ui::lv_win::updateFitParent);
    lv_win_set_title(p_window, "  luxio overlay");

    lv_obj_t* p_label = lx::ui::lv_label::create(p_window);
    m_basicScreen.addLvObjPositionUpdater(p_label, [](lv_obj_t* mp_promptLabel) {
        lv_obj_align(mp_promptLabel, nullptr, LV_ALIGN_IN_TOP_LEFT, lx::ui::size::MARGIN(), lx::ui::size::MARGIN());
    });
    lv_label_set_text(p_label, "Hello world!");

    LOG("done");
}

MainScreen::~MainScreen() {}

void MainScreen::renderScreen() { m_basicScreen.renderScreen(); }

void MainScreen::procFrame() {
    if (m_basicScreen.returnButtonPressed()) {
        lx::ui::Controller::stop();
    }
}
