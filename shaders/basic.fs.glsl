uniform sampler2D diffuse;
varying vec2 v_texCoord;
varying vec4 v_colValue;

void main(void) {
      //gl_FragColor = v_colValue;
      gl_FragColor = texture2D(diffuse, v_texCoord) * v_colValue;
}
