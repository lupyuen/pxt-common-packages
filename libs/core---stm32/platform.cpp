#include "pxt.h"
extern "C" void debug_print(const char *s);    //  TODO: Write a string to the buffered debug log.
extern "C" void debug_println(const char *s);  //  TODO: Write a string plus newline to the buffered debug log.
extern "C" void debug_flush(void);             //  TODO: Flush the buffer of the debug log so that buffered data will appear.

namespace pxt {

static void initRandomSeed() {
    debug_println("initRandomSeed");
    int seed = 0xC0DA1;
    /*
    auto pinTemp = LOOKUP_PIN(TEMPERATURE);
    if (pinTemp)
        seed *= pinTemp->getAnalogValue();
    auto pinLight = LOOKUP_PIN(LIGHT);
    if (pinLight)
        seed *= pinLight->getAnalogValue();
    */
    seedRandom(seed);
}

void platformSendSerial(const char *data, int len) {
    debug_println("platformSendSerial");
    /*
    if (!serial) {
        serial = new codal::_mbed::Serial(USBTX, NC);
        serial->baud(9600);
    }
    serial->send((uint8_t*)data, len);
    */
}

void platform_init() {
    debug_println("platform_init");
    initRandomSeed();
    setSendToUART(platformSendSerial);

/*
    if (*HF2_DBG_MAGIC_PTR == HF2_DBG_MAGIC_START) {
        *HF2_DBG_MAGIC_PTR = 0;
        // this will cause alignment fault at the first breakpoint
        globals[0] = (TValue)1;
    }
*/
}

}

void cpu_clock_init() {
    debug_println("cpu_clock_init");
    devTimer.init();
}
