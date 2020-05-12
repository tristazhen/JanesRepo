define([
    ], function(
        ) {
    'use strict';

    let S3MPixelFormat = {
        LUMINANCE_8 : 1,
        LUMINANCE_16 : 2,
        ALPHA : 3,
        ALPHA_4_LUMINANCE_4 : 4,
        LUMINANCE_ALPHA : 5,
        RGB_565 : 6,
        BGR565 : 7,
        RGB : 10,
        BGR : 11,
        ARGB : 12,
        ABGR : 13,
        BGRA : 14,
        WEBP : 25,
        RGBA : 28,
        DXT1 : 17,
        DXT2 : 18,
        DXT3 : 19,
        DXT4 : 20,
        DXT5 : 21
    };
    return Object.freeze(S3MPixelFormat);
});
