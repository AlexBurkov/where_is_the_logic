#pragma once

#include <string>
#include "vector.h"

using TString = std::string;

namespace NString {
    bool EndsWith(const TString& value, const TString& ending);
    bool StartsWith(const TString& value, const TString& prefix);
    bool Contains(const TString& value, const char searchSymbol);
    TString ToLower(TString value);

    TVector<TString> Split(const TString& value, const char del, bool skipEmpty = false);
}
