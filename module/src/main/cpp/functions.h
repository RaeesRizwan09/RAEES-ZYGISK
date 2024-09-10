#ifndef ZYCHEATS_SGUYS_FUNCTIONS_H
#define ZYCHEATS_SGUYS_FUNCTIONS_H

// here you can define variables for the patches
bool cGod;
bool addCurrency;

int (*GetCurrency)(void *instance);
int hGetCurrency(void *instance) {
    if (instance!= NULL) {
        if (addCurrency) {
            return INT_MAX;
        }
    }
}

void Hooks() {
    IL2Cpp::Il2CppAttach();
    Tools::Hook((void *) (uintptr_t)IL2Cpp::Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("WalletModel") , OBFUSCATE("GetCurrency"), 1), (void *) hGetCurrency, (void **) &GetCurrency);
}

#endif //ZYCHEATS_SGUYS_FUNCTIONS_H
