#include <cstdint>
#include <cstring>
#include <fstream>
#include <stdexcept>

struct bytefile {
    const std::uint8_t*  string_pool_ptr;
    const std::uint32_t* public_symbols_ptr;
    const std::uint8_t*  code_ptr;
    const std::uint32_t* global_area_ptr;
    std::uint32_t        string_pool_size;
    std::uint32_t        global_area_size;
    std::uint32_t        public_symbols_count;
    std::uint8_t         buffer[];
};

enum Instructions {
    BINOP_add    = 0x01, // BINOP +
    BINOP_sub    = 0x02, // BINOP -
    BINOP_mul    = 0x03, // BINOP *
    BINOP_div    = 0x04, // BINOP /
    BINOP_rem    = 0x05, // BINOP %
    BINOP_lt     = 0x06, // BINOP <
    BINOP_le     = 0x07, // BINOP <=
    BINOP_gt     = 0x08, // BINOP >
    BINOP_ge     = 0x09, // BINOP >=
    BINOP_eq     = 0x0A, // BINOP ==
    BINOP_ne     = 0x0B, // BINOP !=
    BINOP_and    = 0x0C, // BINOP &&
    BINOP_or     = 0x0D, // BINOP !!
    CONST        = 0x10, // CONST, int
    STRING       = 0x11, // STRING, string
    SEXP         = 0x12, // SEXP, string, int
    STI          = 0x13, // STI
    STA          = 0x14, // STA
    JMP          = 0x15, // JMP, int
    END          = 0x16, // END
    RET          = 0x17, // RET
    DROP         = 0x18, // DROP
    DUP          = 0x19, // DUP
    SWAP         = 0x1A, // SWAP
    ELEM         = 0x1B, // ELEM
    LD_G         = 0x20, // LD, G(int)
    LD_L         = 0x21, // LD, L(int)
    LD_A         = 0x22, // LD, A(int)
    LD_C         = 0x23, // LD, C(int)
    LDA_G        = 0x30, // LDA, G(int)
    LDA_L        = 0x31, // LDA, L(int)
    LDA_A        = 0x32, // LDA, A(int)
    LDA_C        = 0x33, // LDA, C(int)
    ST_G         = 0x40, // ST, G(int)
    ST_L         = 0x41, // ST, L(int)
    ST_A         = 0x42, // ST, A(int)
    ST_C         = 0x43, // ST, C(int)
    CJMPz        = 0x50, // CJMPz, int
    CJMPnz       = 0x51, // CJMPnz, int
    BEGIN        = 0x52, // BEGIN, int, int
    CBEGIN       = 0x53, // CBEGIN, int, int
    CLOSURE      = 0x54, // CLOSURE, int, n: int, [byte, int][n]
    CALLC        = 0x55, // CALLC, int
    CALL         = 0x56, // CALL, int, int
    TAG          = 0x57, // TAG, string, int
    ARRAY        = 0x58, // ARRAY, int
    FAIL         = 0x59, // FAIL, int, int
    LINE         = 0x5A, // LINE, int
    PATT_str     = 0x60, // PATT =str
    PATT_string  = 0x61, // PATT #string
    PATT_array   = 0x62, // PATT #array
    PATT_sexp    = 0x63, // PATT #sexp
    PATT_ref     = 0x64, // PATT #ref
    PATT_val     = 0x65, // PATT #val
    PATT_fun     = 0x66, // PATT #fun
    CALL_Lread   = 0x70, // CALL Lread
    CALL_Lwrite  = 0x71, // CALL Lwrite
    CALL_Llength = 0x72, // CALL Llength
    CALL_Lstring = 0x73, // CALL Lstring
    CALL_Barray  = 0x74, // CALL Barray, int
};

auto read_bytefile(char* filename) -> bytefile* {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file) { throw std::runtime_error("Error opening file: " + std::string(std::strerror(errno))); }

    std::streamsize size = file.tellg();
    if (size < 0) { throw std::runtime_error("Error determining file size: " + std::string(std::strerror(errno))); }
    file.seekg(0, std::ios::beg);

    bytefile* byte_file = static_cast<bytefile*>(std::malloc(sizeof(char*) * 4 + size));

    if (!file.read(reinterpret_cast<char*>(byte_file->string_pool_size), size)) {
        throw std::runtime_error("Error reading file: " + std::string(std::strerror(errno)));
    }

    file.close();

    byte_file->public_symbols_ptr = reinterpret_cast<std::uint32_t*>(byte_file->buffer);
    byte_file->string_pool_ptr    = byte_file->buffer + byte_file->public_symbols_count * 2 * sizeof(int);
    byte_file->code_ptr           = byte_file->string_pool_ptr + byte_file->string_pool_size;
    byte_file->global_area_ptr    = new std::uint32_t[byte_file->global_area_size];

    return byte_file;
}
