#ifndef AXE_GAME_PROJECT_COMPONENT_H
#define AXE_GAME_PROJECT_COMPONENT_H

struct Bounds {
    int left;
    int right;
    int upper;
    int lower;
};

class Component {
public:
    Component(int left, int right, int upper, int lower);

    bool collides_with(const Component& that);

    [[nodiscard]] bool isAbove(int pos) const;
    [[nodiscard]] bool isBelow(int pos) const;
    [[nodiscard]] bool isLeftOf(int pos) const;
    [[nodiscard]] bool isRightOf(int pos) const;

protected:
    Bounds bounds{};
};

#endif
