friend std::ostream& operator<< (std::ostream &out, Complex &a){
    if(a.imag){
        out << noshowpos << a.real << showpos << imag << "i\n";
    }else{
        cout << noshowpos << a.real << "\n";
    }
    return out;
}

bool Complex::operator<(Complex &a){
    if(this->magnitude()<a.magnitude){
        return true;
    }
    else{
        return false;
    }
}
