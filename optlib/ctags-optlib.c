/*
 * Generated by ./misc/optlib2c from optlib/ctags-optlib.ctags, Don't edit this manually.
 */
#include "general.h"
#include "parse.h"
#include "routines.h"
#include "field.h"
#include "xtag.h"


static void initializeCtagsParser (const langType language CTAGS_ATTR_UNUSED)
{
}

extern parserDefinition* CtagsParser (void)
{
    static const char *const extensions [] = {
        "ctags",
        NULL
    };

    static const char *const aliases [] = {
        NULL
    };

    static const char *const patterns [] = {
        NULL
    };

    static kindDefinition CtagsKindTable [] = {
        {
            true, 'l', "langdef", "language definitions",
        },
        {
            true, 'k', "kind", "kind definitions",
        },
    };
    static tagRegexTable CtagsTagRegexTable [] = {
        {   "^--langdef=([^ \t]+)$", "\\1",
            "l", "{scope=set}", NULL, false
        },
        {   "^--regex-[^=]+=.*/.,(.+)/.*", "\\1",
            "k", "{scope=ref}", NULL, false
        },
        {   "^--kinddef-[^=]+=.,([^,]+),.*", "\\1",
            "k", "{scope=ref}", NULL, false
        },
    };


    parserDefinition* const def = parserNew ("Ctags");

    def->enabled       = true;
    def->extensions    = extensions;
    def->patterns      = patterns;
    def->aliases       = aliases;
    def->method        = METHOD_NOT_CRAFTED|METHOD_REGEX;
    def->useCork       = 1;
    def->kindTable     = CtagsKindTable;
    def->kindCount     = ARRAY_SIZE(CtagsKindTable);
    def->tagRegexTable = CtagsTagRegexTable;
    def->tagRegexCount = ARRAY_SIZE(CtagsTagRegexTable);
    def->initialize    = initializeCtagsParser;

    return def;
}
