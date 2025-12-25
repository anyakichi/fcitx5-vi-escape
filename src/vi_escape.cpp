#include <fcitx-utils/key.h>
#include <fcitx-utils/keysym.h>
#include <fcitx/addonfactory.h>
#include <fcitx/addoninstance.h>
#include <fcitx/addonmanager.h>
#include <fcitx/event.h>
#include <fcitx/inputcontext.h>
#include <fcitx/inputpanel.h>
#include <fcitx/instance.h>

using namespace fcitx;

namespace {

static bool isEscOrCtrlLBracket(const Key &k)
{
    if (k.sym() == FcitxKey_Escape) {
        return true;
    }

    if ((k.states() & KeyState::Ctrl) && k.sym() == FcitxKey_bracketleft) {
        return true;
    }

    return false;
}

class ViEscape final : public AddonInstance {
public:
    explicit ViEscape(Instance *instance)
        : instance_(instance)
    {
        handler_ = instance_->watchEvent(EventType::InputContextKeyEvent,
            EventWatcherPhase::PostInputMethod, [this](Event &event) {
                auto &keyEvent = static_cast<KeyEvent &>(event);
                if (keyEvent.isRelease()) {
                    return;
                }

                if (!isEscOrCtrlLBracket(keyEvent.key())) {
                    return;
                }

                if (keyEvent.accepted() || keyEvent.filtered()) {
                    return;
                }

                instance_->deactivate();
            });
    }

private:
    Instance *instance_;
    std::unique_ptr<HandlerTableEntry<EventHandler>> handler_;
};

class ViEscapeFactory final : public AddonFactory {
public:
    AddonInstance *create(AddonManager *manager) override
    {
        return new ViEscape(manager->instance());
    }
};

}

FCITX_ADDON_FACTORY(ViEscapeFactory)
