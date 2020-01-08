#ifndef PLAT_VALUE_H
#define PLAT_VALUE_H

#include <string>
#include <vector>

namespace Plat
{
  class Param;
  class FloatParam;
  class FieldParam;
  class IntParam;

  class Value {
    friend class Param;
  public:
    enum Type {
      NONE  = 0x00,
      CLOUD = 0x01,
      CURVE = 0x02,
      FIELD = 0x04,
      FLOAT = 0x08,
      INT   = 0x10,
      WORLD = 0x80
    };

  public:
    static Value* byName(const std::string& name);

  protected:
    Param* mParent;
    std::vector<Param*> mParams;
    int mConsumers;

    FloatParam* floatParam(const std::string& name);
    FloatParam* floatParam(const std::string& name, float min, float def, float max, float inc);
    FieldParam* fieldParam(const std::string& name);
    IntParam*     intParam(const std::string& name);

  public:
    Value();
    virtual ~Value();

    virtual const char* name() const = 0;
    virtual Type type() const = 0;

    virtual bool  constant() const;
    virtual bool  editable() const;
    virtual Type  edittype() const;
    virtual float getFloat() const;
    virtual int   getInt()   const;
    virtual bool  setFloat(float f);
    virtual bool  setInt(int i);

    virtual bool prepare();
    virtual void generate(int xbits, int ybits);
    virtual bool release();
  };
}

#endif
