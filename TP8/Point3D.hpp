template<typename T>

class Point3D{
  private:
    T m_x;
    T m_y;
    T m_z;

  public:
    // Constructeur par défaut
    Point3D()
      :m_x(0), m_y(0), m_z(0)
    {}
    Point3D(const T &x, const T &y, const T &z)
      :m_x(x), m_y(y), m_z(z)
    {}
    // Constructeur par copie
    Point3D(const Point3D &pt)
      :m_x(pt.m_x), m_y(pt.m_y), m_z(pt.m_z)
    {}



    // Surcharge d'opérateur =
    Point3D &operator=(const Point3D &pt){
      if(this != &pt){
        m_x = pt.m_x;
        m_y = pt.m_y;
        m_z = pt.m_z;
      };
      return *this;
    }

    // Surcharge d'opérateur + (avec un autre point)
    Point3D &operator+(const Point3D &pt) const{
      return Point3D(m_x + pt.m_x,
                     m_y + pt.m_y,
                     m_z + pt.m_y);
    }

/* /!\/!\/!\/!\/!\/!\/!\/!\/!\ NEED TO FIX /!\/!\/!\/!\/!\/!\/!\/!\ */
    
    Point3D &operator+(const T &x, const T &y, const T &z){
      return Point3D(m_x + x,
                     m_y + y,
                     m_z + z);
    }

    Point3D &operator<<()

/*
    template<typename U>
    friend class Point3D;

    Point3D<T>(const Point3D<U> &pt)
      :Point3D(static_cast<T>(pt.m_x),
               static_cast<T>(pt.m_y),
               static_cast<T>(pt.m_z)
    )
    {} */




};
