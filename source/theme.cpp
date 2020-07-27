#include "theme.hpp"

namespace theme {

constexpr auto THEME_COLOR = 0x1976D2;

lv_style_t themeColorStyle;

void initialize() {
    LOGSL("Initializing... ");

    lx::ui::lv::initBgColorStyle(themeColorStyle, lv_color_hex(THEME_COLOR));

    LOGEL("done");
}

auto createWindow(lv_obj_t* p_parent) -> lv_obj_t* {
    auto result = lx::ui::lv_win::create(p_parent);
    lv_obj_add_style(result, LV_WIN_PART_HEADER, &themeColorStyle);
    lv_obj_add_style(result, LV_WIN_PART_BG, lx::ui::Controller::getScreenStyle());
    return result;
}

}  // namespace theme
