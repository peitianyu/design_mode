#ifndef __CHAIN_OF_RESPONSIBILITY_H__
#define __CHAIN_OF_RESPONSIBILITY_H__

namespace design_patterns {

class ChainOfResponsibility {
public:
    virtual ~ChainOfResponsibility() = default;

    virtual void SetNext(ChainOfResponsibility* next) = 0;

    virtual void HandleRequest() = 0;
};

} // namespace design_patterns
#endif // !__CHAIN_OF_RESPONSIBILITY_H__