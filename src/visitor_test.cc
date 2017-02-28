#include "visitor_test.hh"

struct myVisitor
:   public csr::base_visitor,
    public csr::visitor<docElement>,
    public csr::visitor<paragraph>
{
    virtual void visit(docElement&)
    { std::cout << "Visiting docElement!!!" << std::endl; }

    virtual void visit(paragraph&)
    { std::cout << "Visiting paragraph!!!" << std::endl; }
};


class myVisitor2
:   public myVisitor3
{
    void visit(docElement2&) { cout << "Visiting docElement2!!!!!" << endl; };
    void visit(paragraph2&) { cout << "Visiting paragraph2!!!!!" << endl; };
};

void testVisitor()
{
    myVisitor vtor;
    paragraph par;
    par_vector pv;
    for (size_t k = 0; k < 3; ++k) { pv.push_back(par); }
    multipleParagraph mpar(pv);
    docElement* doc = &par;
    doc->accept(vtor);
    mpar.accept(vtor);
}

void testCyclicVisitor()
{
    myVisitor2 vtor2;
    paragraph2 par2;
    par2_vector pv2;
    for (size_t k = 0; k < 3; ++k) { pv2.push_back(par2); }
    multipleParagraph2 mpar2(pv2);
    docElement2* doc2 = &par2;
    doc2->accept(vtor2);
    mpar2.accept(vtor2);
}
