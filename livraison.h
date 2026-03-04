#ifndef LIVRAISON_H
#define LIVRAISON_H

class livraison {
public:
    livraison();
    bool estExpress() const;
    bool estFragile() const;
    void rendFragile(bool f =true);
    void rendExpress(bool e =true);
    void reInitialise();

private:
    bool d_express;
    bool d_fragile;
};


#endif // LIVRAISON_H
