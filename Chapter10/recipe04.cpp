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

#include <iostream>
#include <memory>

class base {
public:
    base() = default;
    virtual ~base() = default;
};

class subclass : public base {
public:
    subclass() = default;
    ~subclass() override = default;
};

void foo(base* b) {
    if (dynamic_cast<subclass*>(b)) {
        std::cout << "downcast successful!!\n";
    }
}

int main(void) {
    auto ptr = std::make_unique<subclass>();
    foo(ptr.get());

    return 0;
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>
#include <memory>

class base {
public:
    base() = default;
    virtual ~base() = default;
};

class subclass : public base {
public:
    subclass() = default;
    ~subclass() override = default;
};

void foo(std::shared_ptr<base> b) {
    if (std::dynamic_pointer_cast<subclass>(b)) {
        std::cout << "downcast successful!!\n";
    }
}

int main(void) {
    auto ptr = std::make_shared<subclass>();
    foo(ptr);

    return 0;
}

#endif
