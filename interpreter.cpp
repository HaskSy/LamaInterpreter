enum Instructions {
  BINOP_add = 0x01,    // BINOP +
  BINOP_sub = 0x02,    // BINOP -
  BINOP_mul = 0x03,    // BINOP *
  BINOP_div = 0x04,    // BINOP /
  BINOP_rem = 0x05,    // BINOP %
  BINOP_lt = 0x06,     // BINOP <
  BINOP_le = 0x07,     // BINOP <=
  BINOP_gt = 0x08,     // BINOP >
  BINOP_ge = 0x09,     // BINOP >=
  BINOP_eq = 0x0A,     // BINOP ==
  BINOP_ne = 0x0B,     // BINOP !=
  BINOP_and = 0x0C,    // BINOP &&
  BINOP_or = 0x0D,     // BINOP !!
  CONST = 0x10,        // CONST, int
  STRING = 0x11,       // STRING, string
  SEXP = 0x12,         // SEXP, string, int
  STI = 0x13,          // STI
  STA = 0x14,          // STA
  JMP = 0x15,          // JMP, int
  END = 0x16,          // END
  RET = 0x17,          // RET
  DROP = 0x18,         // DROP
  DUP = 0x19,          // DUP
  SWAP = 0x1A,         // SWAP
  ELEM = 0x1B,         // ELEM
  LD_G = 0x20,         // LD, G(int)
  LD_L = 0x21,         // LD, L(int)
  LD_A = 0x22,         // LD, A(int)
  LD_C = 0x23,         // LD, C(int)
  LDA_G = 0x30,        // LDA, G(int)
  LDA_L = 0x31,        // LDA, L(int)
  LDA_A = 0x32,        // LDA, A(int)
  LDA_C = 0x33,        // LDA, C(int)
  ST_G = 0x40,         // ST, G(int)
  ST_L = 0x41,         // ST, L(int)
  ST_A = 0x42,         // ST, A(int)
  ST_C = 0x43,         // ST, C(int)
  CJMPz = 0x50,        // CJMPz, int
  CJMPnz = 0x51,       // CJMPnz, int
  BEGIN = 0x52,        // BEGIN, int, int
  CBEGIN = 0x53,       // CBEGIN, int, int
  CLOSURE = 0x54,      // CLOSURE, int, n: int, [byte, int][n]
  CALLC = 0x55,        // CALLC, int
  CALL = 0x56,         // CALL, int, int
  TAG = 0x57,          // TAG, string, int
  ARRAY = 0x58,        // ARRAY, int
  FAIL = 0x59,         // FAIL, int, int
  LINE = 0x5A,         // LINE, int
  PATT_str = 0x60,     // PATT =str
  PATT_string = 0x61,  // PATT #string
  PATT_array = 0x62,   // PATT #array
  PATT_sexp = 0x63,    // PATT #sexp
  PATT_ref = 0x64,     // PATT #ref
  PATT_val = 0x65,     // PATT #val
  PATT_fun = 0x66,     // PATT #fun
  CALL_Lread = 0x70,   // CALL Lread
  CALL_Lwrite = 0x71,  // CALL Lwrite
  CALL_Llength = 0x72, // CALL Llength
  CALL_Lstring = 0x73, // CALL Lstring
  CALL_Barray = 0x74,  // CALL Barray, int
};
