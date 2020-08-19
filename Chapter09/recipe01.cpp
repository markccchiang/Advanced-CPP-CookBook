//
// Copyright (C) 2019 Rian Quinn <user@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// -----------------------------------------------------------------------------
#ifdef EXAMPLE01

#include <array>
#include <memory>
#include <iostream>

class hero {
public:
    virtual ~hero() = default;

    virtual bool attack(int, int) const = 0;
};

class spiderman : public hero {
public:
    bool attack(int x, int) const override {
        return x == 0 ? true : false;
    }
};

class captain_america : public hero {
public:
    bool attack(int, int y) const override {
        return y == 0 ? true : false;
    }
};

int main(void) {
    std::array<std::unique_ptr<hero>, 2> heros{
            std::make_unique<spiderman>(),
            std::make_unique<captain_america>()
    };

    for (const auto &h : heros) {
        std::cout << h->attack(0, 42) << '\n';
    }

    return 0;
}

// 1
// 0

#endif
