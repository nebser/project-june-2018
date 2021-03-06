#ifndef DATA_H_
#define DATA_H_

#include <iostream>
#include <string>

struct Command {
    enum Type {
        GLOBAL_DIR,
        INSTRUCTION,
        END_DIR,
        DEFINITION,
        SECTION,
        ALIGN_DIR,
        SKIP_DIR,
        LABEL,
        EMPTY
    };

    std::string name;
    Type type;

    Command(const std::string& name, Type type) : name(name), type(type) {}
};

const auto DUMMY_COMMAND = Command("empty", Command::EMPTY);

class RelocationData {
   public:
    enum Type { APSOLUTE, RELATIVE };

    RelocationData(unsigned int offset, Type type, unsigned int value)
        : offset(offset), type(type), value(value) {}

    unsigned int getOffset() const { return offset; }

    Type getType() const { return type; }

    std::string getTypeDescription() const {
        return type == APSOLUTE ? "A" : "R";
    }

    unsigned int getValue() const { return value; }

    friend std::ostream& operator<<(std::ostream& os,
                                    const RelocationData& relData) {
        os << std::hex << "0x" << relData.offset << '\t'
           << relData.getTypeDescription() << '\t' << std::dec << relData.value
           << std::endl;
        return os;
    }

   private:
    unsigned int offset;
    Type type;
    unsigned int value;
};

#endif