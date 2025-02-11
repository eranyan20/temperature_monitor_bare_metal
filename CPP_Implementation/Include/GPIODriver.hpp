#pragma once

class GPIODriver {
public:
    enum Pin { GREEN_LED, YELLOW_LED, RED_LED };
    bool init();
    void digitalWrite(Pin pin, bool state);
};
