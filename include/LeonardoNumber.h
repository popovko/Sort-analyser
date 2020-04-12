#ifndef LEONARDONUMBER_H
#define LEONARDONUMBER_H

class LeonardoNumber
{
public:
    /**  Default ctor.  **/
    LeonardoNumber (void) throw () : b (1), c (1)
    { return; }

    /**  Copy ctor.  **/
    LeonardoNumber (const LeonardoNumber & _l) throw () : b (_l.b), c (_l.c)
    { return; }

    /**
    **  Return the "gap" between the actual Leonardo number and the
    **  preceding one.
    **/
    unsigned gap (void) const throw ()
    { return b - c; }


    /**  Perform an "up" operation on the actual number.  **/
    LeonardoNumber & operator ++ (void) throw ()
    { unsigned s = b; b = b + c + 1; c = s; return * this; }

    /**  Perform a "down" operation on the actual number.  **/
    LeonardoNumber & operator -- (void) throw ()
    { unsigned s = c; c = b - c - 1; b = s; return * this; }

    /**  Return "companion" value.  **/
    unsigned operator ~ (void) const throw ()
    { return c; }

    /**  Return "actual" value.  **/
    operator unsigned (void) const throw ()
    { return b; }


private:
    unsigned b;   /**  Actual number.  **/
    unsigned c;   /**  Companion number.  **/
};

inline void sift (int *, unsigned, LeonardoNumber) throw ();

/**  Perform a "semi-trinkle" operation.  **/
inline void semitrinkle (int *, unsigned, unsigned long long, LeonardoNumber) throw ();

/**  Perform a "trinkle" operation.  **/
inline void trinkle (int *, unsigned, unsigned long long, LeonardoNumber) throw ();

#endif // LEONARDONUMBER_H
