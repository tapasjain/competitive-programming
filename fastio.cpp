// ------------------------------------------ Neg/Pos Integers -------------------------------------------------------
#define gc getchar
inline int inp() {
    char c = gc();
    int neg = 0;
    while(c<'0' || c>'9') {
        if(c == '-') {
            neg = 1; c = gc(); break;
        }
        c = gc();
    } 
    int ret = 0;
    while(c>='0' && c<='9') {
        ret = (ret << 3) + (ret << 1) + c - 48;
        c = gc();
    }
    if(neg) return -ret;
    else return ret;
}

// ------------------------------------------ Pos Integers -------------------------------------------------------
#define gc getchar
inline int inp() {
    char c = gc();
    while(c<'0' || c>'9') c = gc();
    int ret = 0;
    while(c>='0' && c<='9') {
        ret = (ret << 3) + (ret << 1) + c - 48;
        c = gc();
    }
    return ret;
}

// ------------------------------------------ Neg/Pos LL -------------------------------------------------------
#define gc getchar
#define LL long long
inline LL inp() {
    char c = gc();
    int neg = 0;
    while(c<'0' || c>'9') {
        if(c == '-') {
            neg = 1; c = gc(); break;
        }
        c = gc();
    } 
    LL ret = 0;
    while(c>='0' && c<='9') {
        ret = (ret << 3) + (ret << 1) + c - 48;
        c = gc();
    }
    if(neg) return -ret;
    else return ret;
}


// ------------------------------------------ Pos LL -------------------------------------------------------
#define gc getchar
#define LL long long
inline LL inp() {
    char c = gc();
    while(c<'0' || c>'9') c = gc();
    LL ret = 0;
    while(c>='0' && c<='9') {
        ret = (ret << 3) + (ret << 1) + c - 48;
        c = gc();
    }
    return ret;
}

// ------------------------------------------ Neg/Pos Double -------------------------------------------------------
#define gc getchar
inline double inp() {
    int neg = 0;
    char c = gc();
    while(c<'0' || c>'9') {
        if(c=='-') {
            neg = 1; c = gc(); break;
        }
        c = gc();
    }
    double ret = 0.0;
    while(c>='0' && c<='9') {
        ret = ret*10.0 + c - 48;
        c = gc();
    }
    double mul = 1.0;
    if(c == '.') {
        c = gc();
        while(c>='0' && c<='9') {
            mul /= 10.0;
            ret += (c-48)*mul;
            c=gc();
        }
    }
    if(neg) return ret*-1.0;
    else return ret;
}

// ------------------------------------------ Strings small characters-------------------------------------------------------
#define gc getchar
inline int inp(char *s) {
    int len = 0;
    char c = gc();
    while(c<'a' || c>'z') c=gc();
    while(c>='a' && c<='z') {
        s[len++]=c; c=gc();
    }
    s[len] = '\0';
    return len;
}

// ------------------------------------------ Strings capital characters-------------------------------------------------------
#define gc getchar
inline int inp(char *s) {
    int len = 0;
    char c = gc();
    while(c<'A' || c>'Z') c=gc();
    while(c>='A' && c<='Z') {
        s[len++]=c; c=gc();
    }
    s[len] = '\0';
    return len;
}

// ------------------------------------------ Strings capital/small characters-------------------------------------------------------
#define gc getchar
inline int inp(char *s) {
    int len = 0;
    char c = gc();
    while((c<'a' || c>'z') && (c<'A' || c>'Z')) c=gc();
    while((c>='a' && c<='z') || (c>='A' && c<='Z')) {
        s[len++]=c; c=gc();
    }
    s[len] = '\0';
    return len;
}
