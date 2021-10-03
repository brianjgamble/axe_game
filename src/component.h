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
    virtual ~Component() = default;

    [[nodiscard]] bool collides_with(const Component& that) const;

    [[nodiscard]] bool isAbove(int pos) const;
    [[nodiscard]] bool isBelow(int pos) const;
    [[nodiscard]] bool isLeftOf(int pos) const;
    [[nodiscard]] bool isRightOf(int pos) const;

    virtual void moveLeft(int amount) {}
    virtual void moveRight(int amount) {}
    virtual void moveUp(int amount) {}
    virtual void moveDown(int amount) {}

protected:
    Bounds bounds{};
};

#endif
