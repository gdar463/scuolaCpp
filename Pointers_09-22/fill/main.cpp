// Per gestire meglio i progetti uso CMake e un'unico main file
// per i vari main li divido attraverso namespace
#ifdef USING_CMAKE
namespace Fill {
#endif

int main() { return 1; }

#ifdef USING_CMAKE
}
#endif
