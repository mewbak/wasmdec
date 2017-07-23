#include "Emitter.h"
using namespace wasmdec;
using namespace std;

Emitter::Emitter() {
	// Preamble
	str << "// Decompiled Web Assembly generated by wasmdec. Preamble:" << endl
	<< "#include <stdint.h> // For the bit size specific types" << endl
	<< "#include <math.h> // For certian WASM operations" << endl
	<< "typedef const char* wasm_table_t; // WASM tables" << endl
	<< "// Bit size specific types not declared in stdint.h:" << endl
	<< "typedef float float32_t;" << endl
	<< "typedef double float64_t;" << endl
	<< "// C implementation of WASM expressions:" << endl
	<< "unsigned int _rotl(const unsigned int value, int shift) {\n"
	"\tif ((shift &= sizeof(value) * 8 - 1) == 0)\n"
	"\t\treturn value;\n"
	"\treturn (value << shift) | (value >> (sizeof(value)*8 - shift));\n"
	"}\n"
	"unsigned int _rotr(const unsigned int value, int shift) {\n"
    "\tif ((shift &= sizeof(value) * 8 - 1) == 0)\n"
    "\t\treturn value;\n"
    "\treturn (value >> shift) | (value << (sizeof(value)*8 - shift));\n}\n"
    "#define MAX(a,b) ((a) > (b) ? a : b)\n"
	"#define MIN(a,b) ((a) < (b) ? a : b)\n"
	"// Host functions: used to request information from host machine.\n"
	"extern int32_t host_has_feature(const char* feature);\n"
	"extern void host_grow_memory(int32_t size);\n"
	"extern int32_t host_get_current_memory(void);\n"
	"extern int32_t host_get_page_size(void);\n"
	<< "// End of preamble" << endl << endl;
}
stringstream& Emitter::operator<<(string out) {
	str << out;
	return str;
}
void Emitter::comment(string cmt) {
	str << "// " << cmt << endl;
}
void Emitter::ln() {
	str << endl;
}
string Emitter::getCode() {
	return str.str();
}