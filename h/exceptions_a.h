#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <string>
#include "utils.h"

class AssemblerException {
   public:
    virtual std::string error() const = 0;
};

class ParserException : public AssemblerException {
   public:
    ParserException(const std::string& token, int lineNumber)
        : token(token), lineNumber(lineNumber) {}

    std::string error() const override {
        return "Invalid token " + token + " at line " +
               Utils::convertToString(lineNumber);
    }

   private:
    std::string token;
    int lineNumber;
};

class StreamException : public AssemblerException {
   public:
    std::string error() const override { return "End of the stream reached"; }
};

class SystemException : public AssemblerException {
   public:
    SystemException(const std::string& error) : errorReason(error) {}

    std::string error() const override {
        return "System error: " + errorReason;
    }

   private:
    std::string errorReason;
};

class SymbolAlreadyDefinedException : public AssemblerException {
   public:
    SymbolAlreadyDefinedException(const std::string& symbol) : symbol(symbol) {}

    std::string error() const override {
        return "Symbol " + symbol + " already defined";
    }

   private:
    std::string symbol;
};

class NoSectionDefined : public AssemblerException {
   public:
    NoSectionDefined(const std::string& symbol) : symbol(symbol) {}

    std::string error() const override {
        return "No section defined before symbol " + symbol;
    }

   private:
    std::string symbol;
};

class SymbolNotDefined : public AssemblerException {
   public:
    SymbolNotDefined(const std::string& symbol) : symbol(symbol) {}

    std::string error() const override {
        return "Symbol " + symbol + " not defined";
    }

   private:
    std::string symbol;
};

class UnknownCommandException : public AssemblerException {
   public:
    UnknownCommandException(const std::string& command) : command(command) {}

    std::string error() const override { return "Unknown command: " + command; }

   private:
    std::string command;
};

class InvalidInstructionSequence : public AssemblerException {
   public:
    InvalidInstructionSequence(const std::string& instruction1,
                               const std::string& instruction2)
        : instruction1(instruction1), instruction2(instruction2) {}

    std::string error() const override {
        return "Invalid instruction sequence " + instruction1 + " " +
               instruction2;
    }

   private:
    std::string instruction1;
    std::string instruction2;
};

class InvalidCommand : public AssemblerException {
   public:
    InvalidCommand(const std::string& section, const std::string& instruction)
        : section(section), instruction(instruction) {}

    std::string error() const override {
        return "Invalid instruction " + instruction + " for section " + section;
    }

   private:
    std::string section;
    std::string instruction;
};

class DecodingException : public AssemblerException {
   public:
    DecodingException(const std::string& text) : text(text) {}

    std::string error() const override { return "DecodingException: " + text; }

   private:
    std::string text;
};

class MemoryException : public AssemblerException {
   public:
    MemoryException(const std::string& text) : text(text) {}

    std::string error() const override { return "Memory Exception: " + text; }

   private:
    std::string text;
};

#endif
