#ifndef REGEX_H
#define REGEX_H

#include <iostream>

enum RegExType {
    Or,
    Concat,
    Repeat,
    Primitive,
    Blank
};

class RegEx {
public:

    RegEx(RegExType re_type) {
        this->re_type = re_type;
    }

    RegExType getType() {
        return re_type;
    }

private:
    RegExType re_type;
};

class RegExOr: public RegEx {
private:
    RegEx *first;
    RegEx *second;

public:
    RegExOr(RegEx *first, RegEx *second): RegEx(RegExType::Or) {
        this->first = first;
        this->second = second;
    }

    RegEx *getFirst() {
        return first;
    }

    RegEx *getSecond() {
        return second;
    }
};

class RegExConcat: public RegEx {
private:
    RegEx *first;
    RegEx *second;

public:
    RegExConcat(RegEx *first, RegEx *second): RegEx(RegExType::Concat) {
        this->first = first;
        this->second = second;
    }

    RegEx *getFirst() {
        return first;
    }

    RegEx *getSecond() {
        return second;
    }
};

enum RegExRepeatType {
    ZeroOrMore,
    OneOrMore,
    MinToMax
};

class RegExRepeat: public RegEx {
private:
    RegEx *internal;
    RegExRepeatType r_type;
    int min;
    int max;

public:
    RegExRepeat(RegEx *internal, RegExRepeatType r_type, int min = -1, int max = -1): RegEx(RegExType::Repeat) {
        this->internal = internal;
        this->r_type = r_type;
        this->min = min;
        this->max = max;
    }

    RegEx *getInternal() {
        return internal;
    }

    RegExRepeatType getRepeatType() {
        return r_type;
    }

    int getMin() {
        return min;
    }

    int getMax() {
        return max;
    }
};

class RegExPrimitive: public RegEx {
private:
    std::string mgram;

public:
    RegExPrimitive(std::string mgram): RegEx(RegExType::Primitive) {
        this->mgram = mgram;
    }

    std::string getMgram() {
        return mgram;
    }
};

class RegExBlank: public RegEx {
public:
    RegExBlank(): RegEx(RegExType::Blank) {}
};

#endif