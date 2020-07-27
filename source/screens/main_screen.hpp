#pragma once

#include "lx/debug.hpp"
#include "lx/ui/basic_screen_provider.hpp"

class MainScreen : public lx::ui::IScreen {
    LOGCONSTRUCTM;

   private:
    MainScreen();
    MainScreen(const MainScreen&) = delete;
    ~MainScreen();
    static MainScreen s_instance;

    lx::ui::BasicScreenProvider m_basicScreen;

    virtual void renderScreen() override;
    virtual void procFrame() override;

    virtual inline lv_obj_t* getLvScreenObj() override { return m_basicScreen.getLvScreenObj(); }
    virtual inline lv_group_t* getLvInputGroup() override { return m_basicScreen.getLvInputGroup(); }

   public:
    static inline MainScreen& getInstance() { return s_instance; }
};
